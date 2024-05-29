
#import <UIKit/UIKit.h>
@protocol SJRotationFullscreenNavigationControllerDelegate;

NS_ASSUME_NONNULL_BEGIN
@interface SJRotationFullscreenNavigationController : UINavigationController
- (instancetype)initWithRootViewController:(UIViewController *)rootViewController delegate:(nullable id<SJRotationFullscreenNavigationControllerDelegate>)delegate;
@end


@protocol SJRotationFullscreenNavigationControllerDelegate <NSObject>
- (void)pushViewController:(UIViewController *)viewController animated:(BOOL)animated;
@end
NS_ASSUME_NONNULL_END