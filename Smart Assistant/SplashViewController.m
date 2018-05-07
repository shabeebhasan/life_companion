//
//  SplashViewController.m
//
//

#import "SplashViewController.h"

#import <WebKit/WebKit.h>

#import "CBDefines.h"
#import "CBViewController.h"
#import "UIColor+GILAdditions.h"


@interface SplashViewController ()

@end

@implementation SplashViewController

- (void)viewDidLoad {
    [super viewDidLoad];
}

- (void)viewWillAppear:(BOOL)animated{
    self.timer = [NSTimer scheduledTimerWithTimeInterval:3.0f
                                     target:self selector:@selector(methodB:) userInfo:nil repeats:NO];
}

#pragma mark - CBViewControllerDelegate

- (void)chatBotController:(CBViewController *)controller
didRequestUserImageWithCompletionBlock:(CBUserImageSelectedCompletionBlock)completionBlock {
    _userImageSelectedCompletionBlock = [completionBlock copy];
    
    // Present the image picker
    UIImagePickerController *picker = [[UIImagePickerController alloc] init];
    picker.delegate = self;
    picker.sourceType = UIImagePickerControllerSourceTypePhotoLibrary;
    [((UINavigationController *)self.presentedViewController).topViewController
     presentViewController:picker
     animated:YES
     completion:NULL];
}

- (void)chatBotController:(CBViewController *)controller
shouldPresentViewController:(UIViewController *)viewController {
    UINavigationController *chatBotNavigationController =
    (UINavigationController *)self.presentedViewController;
    [chatBotNavigationController pushViewController:viewController animated:YES];
}

#pragma mark - UIImagePickerControllerDelegate

- (void)imagePickerController:(UIImagePickerController *)picker
didFinishPickingMediaWithInfo:(NSDictionary<NSString *, id> *)info {
    [((UINavigationController *)self.presentedViewController).topViewController
     dismissViewControllerAnimated:YES
     completion:NULL];
    if (_userImageSelectedCompletionBlock) {
        _userImageSelectedCompletionBlock(info[UIImagePickerControllerOriginalImage]);
    }
}

- (void)imagePickerControllerDidCancel:(UIImagePickerController *)picker {
    [((UINavigationController *)self.presentedViewController).topViewController
     dismissViewControllerAnimated:YES
     completion:NULL];
    if (_userImageSelectedCompletionBlock) {
        _userImageSelectedCompletionBlock(nil);
    }
}

- (void) navigateMainView{
    [self.timer invalidate];
    self.timer = nil;
    
    CBViewController *viewController = [[CBViewController alloc] init];
    viewController.clientAccessToken = CBApiAiToken;
    viewController.title = @"SMART ASSISTANT";
    viewController.delegate = self;
    
    UINavigationController *navigationController =
    [[UINavigationController alloc] initWithRootViewController:viewController];
    [self presentViewController:navigationController animated:YES completion:NULL];
}

- (void) methodB:(NSTimer *)timer
{
    [self navigateMainView];
}

/*
 #pragma mark - Navigation
 
 // In a storyboard-based application, you will often want to do a little preparation before navigation
 - (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
 // Get the new view controller using [segue destinationViewController].
 // Pass the selected object to the new view controller.
 }
 */

@end
