
#import "SJRotationManager.h"
#import "SJRotationFullscreenViewController.h"

NS_ASSUME_NONNULL_BEGIN
@interface SJRotationManager(Internal)<SJRotationFullscreenViewControllerDelegate>
- (instancetype)_init;
- (UIInterfaceOrientationMask)supportedInterfaceOrientationsForWindow:(nullable UIWindow *)window;
- (__kindof SJRotationFullscreenViewController *)rotationFullscreenViewController;
- (BOOL)pointInside:(CGPoint)point withEvent:(UIEvent *)event;
- (BOOL)allowsRotation NS_REQUIRES_SUPER;
- (void)onDeviceOrientationChanged:(SJOrientation)deviceOrientation;
- (void)rotateToOrientation:(SJOrientation)orientation animated:(BOOL)animated complete:(void(^ _Nullable)(SJRotationManager *mgr))completionHandler;

@property (nonatomic, strong, readonly) UIWindow *window;
@property (nonatomic, readonly, getter=isForcedRotation) BOOL forcedRotation;
@property (nonatomic, readonly) SJOrientation deviceOrientation;
@property (nonatomic) SJOrientation currentOrientation;
- (void)rotationBegin NS_REQUIRES_SUPER;
- (void)rotationEnd NS_REQUIRES_SUPER;
- (void)transitionBegin NS_REQUIRES_SUPER;
- (void)transitionEnd NS_REQUIRES_SUPER;
@end
NS_ASSUME_NONNULL_END