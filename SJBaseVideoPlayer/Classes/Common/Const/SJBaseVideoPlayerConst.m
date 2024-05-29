
#import "SJBaseVideoPlayerConst.h"
#import "SJVideoPlayerPlayStatusDefines.h"

NS_ASSUME_NONNULL_BEGIN

NSInteger const SJPlayerViewTag = 0xFFFFFFF0;
NSInteger const SJPresentViewTag = 0xFFFFFFF1;

@implementation SJPlayerZIndexes
+ (instancetype)shared {
    static id instance;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        instance = [[self alloc] _init];
    });
    return instance;
}

- (instancetype)_init {
    self = [super init];
    if ( self ) {
        _textPopupViewZIndex = -10;
        _promptingPopupViewZIndex = -20;
        _controlLayerViewZIndex = -30;
        _danmakuViewZIndex = -40;
        _placeholderImageViewZIndex = -50;
        _watermarkViewZIndex = -60;
        _subtitleViewZIndex = -70;
        _playbackViewZIndex = -80;
    }
    return self;
}
@end

NSNotificationName const SJVideoPlayerAssetStatusDidChangeNotification = @"SJVideoPlayerAssetStatusDidChangeNotification";

NSNotificationName const SJVideoPlayerDefinitionSwitchStatusDidChangeNotification = @"SJVideoPlayerDefinitionSwitchStatusDidChangeNotification";

NSNotificationName const SJVideoPlayerURLAssetWillChangeNotification = @"SJVideoPlayerURLAssetWillChangeNotification";
NSNotificationName const SJVideoPlayerURLAssetDidChangeNotification = @"SJVideoPlayerURLAssetDidChangeNotification";




NSNotificationName const SJVideoPlayerApplicationDidEnterBackgroundNotification = @"SJVideoPlayerApplicationDidEnterBackgroundNotification";
NSNotificationName const SJVideoPlayerApplicationWillEnterForegroundNotification = @"SJVideoPlayerApplicationWillEnterForegroundNotification";
NSNotificationName const SJVideoPlayerApplicationWillTerminateNotification = @"SJVideoPlayerApplicationWillTerminateNotification";

NSNotificationName const SJVideoPlayerPlaybackControllerWillDeallocateNotification = @"SJVideoPlayerPlaybackControllerWillDeallocateNotification"; ///< 注意: object 为 SJMediaPlaybackController 的对象


NSNotificationName const SJVideoPlayerPlaybackTimeControlStatusDidChangeNotification = @"SJVideoPlayerPlaybackTimeControlStatusDidChangeNotification";
NSNotificationName const SJVideoPlayerPictureInPictureStatusDidChangeNotification = @"SJVideoPlayerPictureInPictureStatusDidChangeNotification";
NSNotificationName const SJVideoPlayerPlaybackDidFinishNotification = @"SJVideoPlayerPlaybackDidFinishNotification";

NSNotificationName const SJVideoPlayerPlaybackDidReplayNotification = @"SJVideoPlayerPlaybackDidReplayNotification";
NSNotificationName const SJVideoPlayerPlaybackWillStopNotification = @"SJVideoPlayerPlaybackWillStopNotification";
NSNotificationName const SJVideoPlayerPlaybackDidStopNotification = @"SJVideoPlayerPlaybackDidStopNotification";
NSNotificationName const SJVideoPlayerPlaybackWillRefreshNotification = @"SJVideoPlayerPlaybackWillRefreshNotification";
NSNotificationName const SJVideoPlayerPlaybackDidRefreshNotification = @"SJVideoPlayerPlaybackDidRefreshNotification";
NSNotificationName const SJVideoPlayerPlaybackWillSeekNotification = @"SJVideoPlayerPlaybackWillSeekNotification";
NSNotificationName const SJVideoPlayerPlaybackDidSeekNotification = @"SJVideoPlayerPlaybackDidSeekNotification";



NSNotificationName const SJVideoPlayerCurrentTimeDidChangeNotification = @"SJVideoPlayerCurrentTimeDidChangeNotification";

NSNotificationName const SJVideoPlayerDurationDidChangeNotification = @"SJVideoPlayerDurationDidChangeNotification";

NSNotificationName const SJVideoPlayerPlayableDurationDidChangeNotification = @"SJVideoPlayerPlayableDurationDidChangeNotification";

NSNotificationName const SJVideoPlayerPresentationSizeDidChangeNotification = @"SJVideoPlayerPresentationSizeDidChangeNotification";

NSNotificationName const SJVideoPlayerPlaybackTypeDidChangeNotification = @"SJVideoPlayerPlaybackTypeDidChangeNotification";

NSNotificationName const SJVideoPlayerScreenLockStateDidChangeNotification = @"SJVideoPlayerScreenLockStateDidChangeNotification";

NSNotificationName const SJVideoPlayerMutedDidChangeNotification = @"SJVideoPlayerMutedDidChangeNotification";

NSNotificationName const SJVideoPlayerVolumeDidChangeNotification = @"SJVideoPlayerVolumeDidChangeNotification";

NSNotificationName const SJVideoPlayerRateDidChangeNotification = @"SJVideoPlayerRateDidChangeNotification";


SJWaitingReason const SJWaitingToMinimizeStallsReason = @"AVPlayerWaitingToMinimizeStallsReason";
SJWaitingReason const SJWaitingWhileEvaluatingBufferingRateReason = @"AVPlayerWaitingWhileEvaluatingBufferingRateReason";
SJWaitingReason const SJWaitingWithNoAssetToPlayReason = @"AVPlayerWaitingWithNoItemToPlayReason";

SJFinishedReason const SJFinishedReasonToEndTimePosition = @"SJFinishedReasonToEndTimePosition";
SJFinishedReason const SJFinishedReasonToTrialEndPosition = @"SJFinishedReasonToTrialEndPosition";

NSString *const SJVideoPlayerNotificationUserInfoKeySeekTime = @"time";
NS_ASSUME_NONNULL_END