//
//  SplashViewController.h
//

#import "ViewController.h"
#import "CBViewController.h"

@interface SplashViewController : UIViewController <CBViewControllerDelegate,UIImagePickerControllerDelegate,UINavigationControllerDelegate>

@property (strong, nonatomic)  NSTimer *timer;
@property (weak, nonatomic) IBOutlet UIImageView *logoView;
@property (strong, nonatomic) NSString *_agentAccessToken;
@property (strong, nonatomic) CBUserImageSelectedCompletionBlock userImageSelectedCompletionBlock;


@end
