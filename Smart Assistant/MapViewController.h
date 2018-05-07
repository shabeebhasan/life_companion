//
//  MapViewController.h
//  Smart Assistant
//
//  Created by Shabeeb Hasan on 04/01/2018.
//  Copyright © 2018 Final Year Project. All rights reserved.
//

#import "ViewController.h"
#import <CoreLocation/CoreLocation.h>

@interface MapViewController : ViewController <CLLocationManagerDelegate>

@property (strong, nonatomic)  NSString *destination;

@end
