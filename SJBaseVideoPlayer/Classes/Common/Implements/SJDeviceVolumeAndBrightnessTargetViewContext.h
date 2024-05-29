
#import "SJDeviceVolumeAndBrightnessControllerDefines.h"

NS_ASSUME_NONNULL_BEGIN
@interface SJDeviceVolumeAndBrightnessTargetViewContext : NSObject<SJDeviceVolumeAndBrightnessTargetViewContext>
@property (nonatomic) BOOL isFullscreen;
@property (nonatomic) BOOL isFitOnScreen;
@property (nonatomic) BOOL isPlayOnScrollView;
@property (nonatomic) BOOL isScrollAppeared;
@property (nonatomic) BOOL isFloatingMode; // 是否进入了小浮窗模式
@property (nonatomic) BOOL isPictureInPictureMode; // 画中画模式
@end
NS_ASSUME_NONNULL_END