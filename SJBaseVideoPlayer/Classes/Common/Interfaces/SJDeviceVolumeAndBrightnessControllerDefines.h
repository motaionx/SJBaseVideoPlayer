
#ifndef SJDeviceVolumeAndBrightnessControllerProtocol_h
#define SJDeviceVolumeAndBrightnessControllerProtocol_h
#import <UIKit/UIKit.h>
@protocol SJDeviceVolumeAndBrightnessTargetViewContext, SJDeviceVolumeAndBrightnessControllerObserver;

NS_ASSUME_NONNULL_BEGIN
@protocol SJDeviceVolumeAndBrightnessController <NSObject>
- (id<SJDeviceVolumeAndBrightnessControllerObserver>)getObserver;
@property (nonatomic) float volume; // device volume
@property (nonatomic) float brightness; // device brightness

@property (nonatomic, weak, nullable) UIView *target;
@property (nonatomic, strong, nullable) id<SJDeviceVolumeAndBrightnessTargetViewContext> targetViewContext;

- (void)onTargetViewMoveToWindow;
- (void)onTargetViewContextUpdated;
@end

@protocol SJDeviceVolumeAndBrightnessTargetViewContext <NSObject>
@property (nonatomic, readonly) BOOL isFullscreen;
@property (nonatomic, readonly) BOOL isFitOnScreen;
@property (nonatomic, readonly) BOOL isPlayOnScrollView;
@property (nonatomic, readonly) BOOL isScrollAppeared;
@property (nonatomic, readonly) BOOL isFloatingMode;    // 小窗口悬浮模式
@property (nonatomic, readonly) BOOL isPictureInPictureMode; // 画中画模式
@end

@protocol SJDeviceVolumeAndBrightnessControllerObserver
@property (nonatomic, copy, nullable) void(^volumeDidChangeExeBlock)(id<SJDeviceVolumeAndBrightnessController> mgr, float volume);
@property (nonatomic, copy, nullable) void(^brightnessDidChangeExeBlock)(id<SJDeviceVolumeAndBrightnessController> mgr, float brightness);
@end
NS_ASSUME_NONNULL_END
#endif /* SJDeviceVolumeAndBrightnessControllerProtocol_h */