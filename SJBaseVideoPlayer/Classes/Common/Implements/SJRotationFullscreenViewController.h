
#import <UIKit/UIKit.h>
@protocol SJRotationFullscreenViewControllerDelegate;

NS_ASSUME_NONNULL_BEGIN
@interface SJRotationFullscreenViewController : UIViewController
@property (nonatomic, weak, nullable) id<SJRotationFullscreenViewControllerDelegate> delegate;
@end

@protocol SJRotationFullscreenViewControllerDelegate <NSObject>
- (UIStatusBarStyle)preferredStatusBarStyleForRotationFullscreenViewController:(SJRotationFullscreenViewController *)viewController;
- (BOOL)prefersStatusBarHiddenForRotationFullscreenViewController:(SJRotationFullscreenViewController *)viewController;
@end
NS_ASSUME_NONNULL_END