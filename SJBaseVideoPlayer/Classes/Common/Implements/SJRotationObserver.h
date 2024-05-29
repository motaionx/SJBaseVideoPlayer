
#import "SJRotationManager.h"

NS_ASSUME_NONNULL_BEGIN
@interface SJRotationObserver : NSObject<SJRotationManagerObserver>
- (instancetype)initWithManager:(SJRotationManager *)manager;

@property (nonatomic, copy, nullable) void(^onRotatingChanged)(id<SJRotationManager> mgr, BOOL isRotating);
@property (nonatomic, copy, nullable) void(^onTransitioningChanged)(id<SJRotationManager> mgr, BOOL isTransitioning);
@end
NS_ASSUME_NONNULL_END