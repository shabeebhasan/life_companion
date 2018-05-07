//
//  MapViewController.m
//  Smart Assistant
//
//  Created by Shabeeb Hasan on 04/01/2018.
//  Copyright © 2018 Final Year Project. All rights reserved.
//

#import "MapViewController.h"
#import <GoogleMaps/GoogleMaps.h>
#import <CoreLocation/CoreLocation.h>

@interface MapViewController ()

@end

@implementation MapViewController{
    GMSMapView *_mapView;
    BOOL _firstLocationUpdate;
    CLLocationManager *locationManager;
    CLLocation *currentLocation;
    CLGeocoder *geocoder;
    CLLocationCoordinate2D coordinate;
}

- (void) getUserLocation{
    geocoder =  [[CLGeocoder alloc]init];
    locationManager = [[CLLocationManager alloc] init];
    locationManager.delegate = self;
    locationManager.distanceFilter = kCLDistanceFilterNone;
    locationManager.desiredAccuracy = kCLLocationAccuracyBest;
    if ([[[UIDevice currentDevice] systemVersion] floatValue] >= 8.0)
        [locationManager requestWhenInUseAuthorization];
    [locationManager startUpdatingLocation];
}

- (void)locationManager:(CLLocationManager *)manager didUpdateToLocation:(CLLocation *)newLocation fromLocation:(CLLocation *)oldLocation{
    [locationManager stopUpdatingLocation];
    coordinate = newLocation.coordinate;
    
    //GMSCameraPosition *camera = [GMSCameraPosition cameraWithLatitude:coordinate.latitude longitude:coordinate.longitude zoom:4];
    //_mapView.camera = camera;
    
    
    [_mapView clear];
    [self fetchPolylineWithDestination:_destination];
}


- (void)fetchPolylineWithDestination:(NSString *)destinationString
{
    NSString *originString = [NSString stringWithFormat:@"%f,%f", coordinate.latitude, coordinate.longitude];
    NSString *destinationEncodedString = [destinationString stringByAddingPercentEncodingWithAllowedCharacters:[NSCharacterSet URLQueryAllowedCharacterSet]];
    NSString *directionsAPI = @"https://maps.googleapis.com/maps/api/directions/json?";
    NSString *directionsUrlString = [NSString stringWithFormat:@"%@&origin=%@&destination=%@&mode=driving&key=AIzaSyAYcNbOz6uNHZ1Ldf8D4-cWoLAayqdibCA", directionsAPI, originString, destinationEncodedString];
    NSURL *directionsUrl = [NSURL URLWithString:directionsUrlString];
    
    NSURLSessionDataTask *fetchDirectionsTask = [[NSURLSession sharedSession] dataTaskWithURL:directionsUrl completionHandler:
                                                 ^(NSData *data, NSURLResponse *response, NSError *error) {
                                                     NSDictionary *json = [NSJSONSerialization JSONObjectWithData:data options:kNilOptions error:&error];
                                                     
                                                     dispatch_sync(dispatch_get_main_queue(), ^{
                                                         if (error) {
                                                             NSLog(@"error: %@", error);
                                                             return;
                                                         }
                                                         
                                                         NSArray *routesArray = [json objectForKey:@"routes"];
                                                         
                                                         GMSPolyline *polyline = nil;
                                                         if ([routesArray count] > 0) {
                                                             NSDictionary *routeDict = [routesArray objectAtIndex:0];
                                                             NSDictionary *routeOverviewPolyline = [routeDict objectForKey:@"overview_polyline"];
                                                             NSString *points = [routeOverviewPolyline objectForKey:@"points"];
                                                             GMSPath *path = [GMSPath pathFromEncodedPath:points];
                                                             polyline = [GMSPolyline polylineWithPath:path];
                                                         }
                                                         
                                                         if(polyline)
                                                             polyline.map = _mapView;
                                                         
                                                     });
                                                 }];
    [fetchDirectionsTask resume];
}

- (void)viewDidLoad {
    [super viewDidLoad];
    if(_destination == nil && [_destination isEqualToString:@""]){
        _destination = @"IBA MAIN CAMPUS";
    }
    GMSCameraPosition *camera = [GMSCameraPosition cameraWithLatitude:-33.868
                                                            longitude:151.2086
                                                                 zoom:12];
    
    _mapView = [GMSMapView mapWithFrame:CGRectZero camera:camera];
    _mapView.settings.compassButton = YES;
    _mapView.settings.myLocationButton = YES;
    
    // Listen to the myLocation property of GMSMapView.
    [_mapView addObserver:self
               forKeyPath:@"myLocation"
                  options:NSKeyValueObservingOptionNew
                  context:NULL];
    
    self.view = _mapView;
    
    // Ask for My Location data after the map has already been added to the UI.
    dispatch_async(dispatch_get_main_queue(), ^{
        _mapView.myLocationEnabled = YES;
    });
    [self getUserLocation];
}

- (void)dealloc {
    [_mapView removeObserver:self
                  forKeyPath:@"myLocation"
                     context:NULL];
}

#pragma mark - KVO updates

- (void)observeValueForKeyPath:(NSString *)keyPath
                      ofObject:(id)object
                        change:(NSDictionary *)change
                       context:(void *)context {
    if (!_firstLocationUpdate) {
        // If the first location update has not yet been recieved, then jump to that
        // location.
        _firstLocationUpdate = YES;
        CLLocation *location = [change objectForKey:NSKeyValueChangeNewKey];
        _mapView.camera = [GMSCameraPosition cameraWithTarget:location.coordinate
                                                         zoom:14];
    }
}

@end
