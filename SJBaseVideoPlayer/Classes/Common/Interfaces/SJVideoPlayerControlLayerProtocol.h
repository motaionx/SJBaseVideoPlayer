
#ifndef SJVideoPlayerControlLayerProtocol_h
#define SJVideoPlayerControlLayerProtocol_h
#import <UIKit/UIKit.h>
#import "SJReachabilityDefines.h"
#import "SJVideoPlayerPlayStatusDefines.h"
#import "SJVideoPlayerPlaybackControllerDefines.h"
#import "SJGestureControllerDefines.h"

@protocol SJPlaybackInfoDelegate,
SJNetworkStatusControlDelegate,
SJLockScreenStateControlDelegate,
SJAppActivityControlDelegate,
SJVolumeBrightnessRateControlDelegate,
SJGestureControllerDelegate,
SJRotationControlDelegate,
SJFitOnScreenControlDelegate,
SJSwitchVideoDefinitionControlDelegate,
SJPlaybackControlDelegate;

@class SJBaseVideoPlayer, SJVideoPlayerURLAsset;



@protocol SJVideoPlayerControlLayerDataSource <NSObject>
@required
- (UIView *)controlView;

@optional
- (void)installedControlViewToVideoPlayer:(__kindof SJBaseVideoPlayer *)videoPlayer;
@end


@protocol SJVideoPlayerControlLayerDelegate <
    SJPlaybackInfoDelegate, 
    SJRotationControlDelegate,
    SJGestureControllerDelegate,
    SJNetworkStatusControlDelegate,
    SJVolumeBrightnessRateControlDelegate,
    SJLockScreenStateControlDelegate,
    SJAppActivityControlDelegate,
    SJFitOnScreenControlDelegate,
    SJSwitchVideoDefinitionControlDelegate,
    SJPlaybackControlDelegate
>
@optional
- (void)controlLayerNeedAppear:(__kindof SJBaseVideoPlayer *)videoPlayer;

- (void)controlLayerNeedDisappear:(__kindof SJBaseVideoPlayer *)videoPlayer;

- (BOOL)controlLayerOfVideoPlayerCanAutomaticallyDisappear:(__kindof SJBaseVideoPlayer *)videoPlayer;

- (void)videoPlayerWillAppearInScrollView:(__kindof SJBaseVideoPlayer *)videoPlayer;

- (void)videoPlayerWillDisappearInScrollView:(__kindof SJBaseVideoPlayer *)videoPlayer;
@end


@protocol SJPlaybackControlDelegate <NSObject>
@optional
- (BOOL)canPerformPlayForVideoPlayer:(__kindof SJBaseVideoPlayer *)videoPlayer;
- (BOOL)canPerformPauseForVideoPlayer:(__kindof SJBaseVideoPlayer *)videoPlayer;
- (BOOL)canPerformStopForVideoPlayer:(__kindof SJBaseVideoPlayer *)videoPlayer;
@end



@protocol SJPlaybackInfoDelegate <NSObject>
@optional

- (void)videoPlayer:(__kindof SJBaseVideoPlayer *)videoPlayer prepareToPlay:(SJVideoPlayerURLAsset *)asset;

- (void)videoPlayerPlaybackStatusDidChange:(__kindof SJBaseVideoPlayer *)videoPlayer;

- (void)videoPlayer:(__kindof SJBaseVideoPlayer *)videoPlayer pictureInPictureStatusDidChange:(SJPictureInPictureStatus)status API_AVAILABLE(ios(14.0));

- (void)videoPlayer:(__kindof SJBaseVideoPlayer *)videoPlayer currentTimeDidChange:(NSTimeInterval)currentTime;
- (void)videoPlayer:(__kindof SJBaseVideoPlayer *)videoPlayer durationDidChange:(NSTimeInterval)duration;
- (void)videoPlayer:(__kindof SJBaseVideoPlayer *)videoPlayer playableDurationDidChange:(NSTimeInterval)duration;

- (void)videoPlayer:(__kindof SJBaseVideoPlayer *)videoPlayer playbackTypeDidChange:(SJPlaybackType)playbackType;
- (void)videoPlayer:(__kindof SJBaseVideoPlayer *)videoPlayer presentationSizeDidChange:(CGSize)size;
@end



@protocol SJVolumeBrightnessRateControlDelegate <NSObject>
@optional
- (void)videoPlayer:(__kindof SJBaseVideoPlayer *)videoPlayer muteChanged:(BOOL)mute;
- (void)videoPlayer:(__kindof SJBaseVideoPlayer *)videoPlayer volumeChanged:(float)volume;
- (void)videoPlayer:(__kindof SJBaseVideoPlayer *)videoPlayer brightnessChanged:(float)brightness;
- (void)videoPlayer:(__kindof SJBaseVideoPlayer *)videoPlayer rateChanged:(float)rate;
@end


@protocol SJRotationControlDelegate <NSObject>
@optional
- (BOOL)canTriggerRotationOfVideoPlayer:(__kindof SJBaseVideoPlayer *)videoPlayer;

- (void)videoPlayer:(__kindof SJBaseVideoPlayer *)videoPlayer willRotateView:(BOOL)isFull;

- (void)videoPlayer:(__kindof SJBaseVideoPlayer *)videoPlayer didEndRotation:(BOOL)isFull;

- (void)videoPlayer:(__kindof SJBaseVideoPlayer *)videoPlayer onRotationTransitioningChanged:(BOOL)isTransitioning;
@end


@protocol SJFitOnScreenControlDelegate <NSObject>
@optional
- (void)videoPlayer:(__kindof SJBaseVideoPlayer *)videoPlayer willFitOnScreen:(BOOL)isFitOnScreen;
- (void)videoPlayer:(__kindof SJBaseVideoPlayer *)videoPlayer didCompleteFitOnScreen:(BOOL)isFitOnScreen;
@end



@protocol SJGestureControllerDelegate <NSObject>
@optional
- (BOOL)videoPlayer:(__kindof SJBaseVideoPlayer *)videoPlayer gestureRecognizerShouldTrigger:(SJPlayerGestureType)type location:(CGPoint)location;

- (void)videoPlayer:(__kindof SJBaseVideoPlayer *)videoPlayer panGestureTriggeredInTheHorizontalDirection:(SJPanGestureRecognizerState)state progressTime:(NSTimeInterval)progressTime;

- (void)videoPlayer:(__kindof SJBaseVideoPlayer *)videoPlayer longPressGestureStateDidChange:(SJLongPressGestureRecognizerState)state;
@end



@protocol SJNetworkStatusControlDelegate <NSObject>
@optional
- (void)videoPlayer:(__kindof SJBaseVideoPlayer *)videoPlayer reachabilityChanged:(SJNetworkStatus)status;
@end



@protocol SJLockScreenStateControlDelegate <NSObject>
@optional
- (void)tappedPlayerOnTheLockedState:(__kindof SJBaseVideoPlayer *)videoPlayer;

- (void)lockedVideoPlayer:(__kindof SJBaseVideoPlayer *)videoPlayer;

- (void)unlockedVideoPlayer:(__kindof SJBaseVideoPlayer *)videoPlayer;
@end



@protocol SJSwitchVideoDefinitionControlDelegate <NSObject>
@optional
- (void)videoPlayer:(__kindof SJBaseVideoPlayer *)videoPlayer switchingDefinitionStatusDidChange:(SJDefinitionSwitchStatus)status media:(id<SJMediaModelProtocol>)media;
@end



@protocol SJAppActivityControlDelegate <NSObject>
@optional
- (void)applicationWillEnterForegroundWithVideoPlayer:(__kindof SJBaseVideoPlayer *)videoPlayer;
- (void)applicationDidBecomeActiveWithVideoPlayer:(__kindof SJBaseVideoPlayer *)videoPlayer;
- (void)applicationWillResignActiveWithVideoPlayer:(__kindof SJBaseVideoPlayer *)videoPlayer;
- (void)applicationDidEnterBackgroundWithVideoPlayer:(__kindof SJBaseVideoPlayer *)videoPlayer;
@end
#endif /* SJVideoPlayerControlLayerProtocol_h */