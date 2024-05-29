
#import <Foundation/Foundation.h>
#import "SJVideoPlayerPlaybackControllerDefines.h"
#import "SJVideoPlayerURLAsset.h"
@protocol SJMediaPlayer, SJMediaPlayerView;

NS_ASSUME_NONNULL_BEGIN
@interface SJMediaPlaybackController : NSObject<SJVideoPlayerPlaybackController>
@property (nonatomic, strong, nullable) SJVideoPlayerURLAsset *media;
@property (nonatomic, strong, readonly, nullable) id<SJMediaPlayer> currentPlayer;
@property (nonatomic, strong, readonly, nullable) __kindof UIView<SJMediaPlayerView> *currentPlayerView;

- (void)playerWithMedia:(SJVideoPlayerURLAsset *)media completionHandler:(void(^)(id<SJMediaPlayer> _Nullable player))completionHandler;

- (UIView<SJMediaPlayerView> *)playerViewWithPlayer:(id<SJMediaPlayer>)player;

- (void)receivedApplicationDidBecomeActiveNotification;
- (void)receivedApplicationWillResignActiveNotification;
- (void)receivedApplicationWillEnterForegroundNotification;
- (void)receivedApplicationDidEnterBackgroundNotification;

@property (nonatomic, copy, nullable) void(^restoreUserInterfaceForPictureInPictureStop)(id<SJVideoPlayerPlaybackController> controller, void(^completionHandler)(BOOL restored));
@end

extern NSNotificationName const SJMediaPlayerAssetStatusDidChangeNotification;
extern NSNotificationName const SJMediaPlayerTimeControlStatusDidChangeNotification;
extern NSNotificationName const SJMediaPlayerPresentationSizeDidChangeNotification;
extern NSNotificationName const SJMediaPlayerPlaybackDidFinishNotification;
extern NSNotificationName const SJMediaPlayerDidReplayNotification;
extern NSNotificationName const SJMediaPlayerDurationDidChangeNotification;
extern NSNotificationName const SJMediaPlayerPlayableDurationDidChangeNotification;
extern NSNotificationName const SJMediaPlayerRateDidChangeNotification;
extern NSNotificationName const SJMediaPlayerVolumeDidChangeNotification;
extern NSNotificationName const SJMediaPlayerMutedDidChangeNotification;

extern NSNotificationName const SJMediaPlayerViewReadyForDisplayNotification;

@protocol SJMediaPlayerView <NSObject>
@property (nonatomic) SJVideoGravity videoGravity;
@property (nonatomic, readonly, getter=isReadyForDisplay) BOOL readyForDisplay;
@end

@protocol SJMediaPlayer <NSObject>
@property (nonatomic, strong, readonly, nullable) NSError *error;
@property (nonatomic, readonly, nullable) SJWaitingReason reasonForWaitingToPlay;
@property (nonatomic, readonly) SJPlaybackTimeControlStatus timeControlStatus;
@property (nonatomic, readonly) SJAssetStatus assetStatus;
@property (nonatomic, readonly) SJSeekingInfo seekingInfo;
@property (nonatomic, readonly) CGSize presentationSize;
@property (nonatomic, readonly) BOOL isReplayed; ///< 是否调用过`replay`方法
@property (nonatomic, readonly) BOOL isPlayed; ///< 是否调用过`play`方法
@property (nonatomic, readonly) BOOL isPlaybackFinished;                        ///< 播放结束
@property (nonatomic, readonly, nullable) SJFinishedReason finishedReason;      ///< 播放结束的reason
@property (nonatomic) NSTimeInterval trialEndPosition;                          ///< 试用结束的位置, 单位秒
@property (nonatomic) float rate;
@property (nonatomic) float volume;
@property (nonatomic, getter=isMuted) BOOL muted;

- (void)seekToTime:(CMTime)time completionHandler:(nullable void (^)(BOOL finished))completionHandler;

@property (nonatomic, readonly) NSTimeInterval currentTime;
@property (nonatomic, readonly) NSTimeInterval duration;    
@property (nonatomic, readonly) NSTimeInterval playableDuration;

- (void)play;
- (void)pause;

- (void)replay;
- (void)report;

- (nullable UIImage *)screenshot;
- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;
@end

extern NSNotificationName const SJMediaPlayerPlaybackTypeDidChangeNotification;


@interface SJMediaPlaybackController (SJSwitchDefinitionExtended)
- (void)replaceMediaForDefinitionMedia:(SJVideoPlayerURLAsset *)definitionMedia NS_REQUIRES_SUPER;
@end
NS_ASSUME_NONNULL_END