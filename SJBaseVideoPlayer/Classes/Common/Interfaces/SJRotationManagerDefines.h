
#ifndef SJRotationManagerProtocol_h
#define SJRotationManagerProtocol_h

#import <UIKit/UIKit.h>
@protocol SJRotationManager, SJRotationManagerObserver;
@class SJPlayModel;
/**
 视图方向
 
 - SJOrientation_Portrait:       竖屏
 - SJOrientation_LandscapeLeft:  全屏, Home键在右侧
 - SJOrientation_LandscapeRight: 全屏, Home键在左侧
 */
typedef NS_ENUM(NSUInteger, SJOrientation) {
    SJOrientation_Portrait = UIDeviceOrientationPortrait,
    SJOrientation_LandscapeLeft = UIDeviceOrientationLandscapeLeft,
    SJOrientation_LandscapeRight = UIDeviceOrientationLandscapeRight,
};

typedef NS_OPTIONS(NSUInteger, SJOrientationMask) {
    SJOrientationMaskPortrait = 1 << SJOrientation_Portrait,
    SJOrientationMaskLandscapeLeft = 1 << SJOrientation_LandscapeLeft,
    SJOrientationMaskLandscapeRight = 1 << SJOrientation_LandscapeRight,
    SJOrientationMaskAll = SJOrientationMaskPortrait | SJOrientationMaskLandscapeLeft | SJOrientationMaskLandscapeRight,
};

NS_ASSUME_NONNULL_BEGIN
@protocol SJRotationManager<NSObject>
- (id<SJRotationManagerObserver>)getObserver;


@property (nonatomic, copy, nullable) BOOL(^shouldTriggerRotation)(id<SJRotationManager> mgr);

@property (nonatomic, getter=isDisabledAutorotation) BOOL disabledAutorotation;

@property (nonatomic) SJOrientationMask autorotationSupportedOrientations;

- (void)rotate;

- (void)rotate:(SJOrientation)orientation animated:(BOOL)animated;

- (void)rotate:(SJOrientation)orientation animated:(BOOL)animated completionHandler:(nullable void(^)(id<SJRotationManager> mgr))completionHandler;

@property (nonatomic, readonly) SJOrientation currentOrientation;

@property (nonatomic, readonly) BOOL isFullscreen;
@property (nonatomic, readonly, getter=isRotating) BOOL rotating; // 是否正在旋转
@property (nonatomic, readonly, getter=isTransitioning) BOOL transitioning; // 是否正在进行转场

@property (nonatomic, weak, nullable) UIView *superview;
@property (nonatomic, weak, nullable) UIView *target;
@end

@protocol SJRotationManagerProtocol <SJRotationManager> @end

@protocol SJRotationManagerObserver <NSObject>
@property (nonatomic, copy, nullable) void(^onRotatingChanged)(id<SJRotationManager> mgr, BOOL isRotating);
@property (nonatomic, copy, nullable) void(^onTransitioningChanged)(id<SJRotationManager> mgr, BOOL isTransitioning);
@end
NS_ASSUME_NONNULL_END
#endif