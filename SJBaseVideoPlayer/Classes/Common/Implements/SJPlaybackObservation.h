
#import <Foundation/Foundation.h>
#import <AVFoundation/AVTime.h>
@class SJBaseVideoPlayer;

NS_ASSUME_NONNULL_BEGIN

@interface SJPlaybackObservation : NSObject
- (instancetype)initWithPlayer:(__kindof SJBaseVideoPlayer *)player;

@property (nonatomic, copy, nullable) void(^playbackStatusDidChangeExeBlock)(__kindof SJBaseVideoPlayer *player);

@property (nonatomic, copy, nullable) void(^playbackDidFinishExeBlock)(__kindof SJBaseVideoPlayer *player);

@property (nonatomic, copy, nullable) void(^assetStatusDidChangeExeBlock)(__kindof SJBaseVideoPlayer *player);

@property (nonatomic, copy, nullable) void(^timeControlStatusDidChangeExeBlock)(__kindof SJBaseVideoPlayer *player);

@property (nonatomic, copy, nullable) void(^pictureInPictureStatusDidChangeExeBlock)(__kindof SJBaseVideoPlayer *player) API_AVAILABLE(ios(14.0));

@property (nonatomic, copy, nullable) void(^willSeekToTimeExeBlock)(__kindof SJBaseVideoPlayer *player, CMTime time);

@property (nonatomic, copy, nullable) void(^didSeekToTimeExeBlock)(__kindof SJBaseVideoPlayer *player, CMTime time);

@property (nonatomic, copy, nullable) void(^didReplayExeBlock)(__kindof SJBaseVideoPlayer *player);

@property (nonatomic, copy, nullable) void(^definitionSwitchStatusDidChangeExeBlock)(__kindof SJBaseVideoPlayer *player);

@property (nonatomic, copy, nullable) void(^currentTimeDidChangeExeBlock)(__kindof SJBaseVideoPlayer *player);

@property (nonatomic, copy, nullable) void(^durationDidChangeExeBlock)(__kindof SJBaseVideoPlayer *player);

@property (nonatomic, copy, nullable) void(^playableDurationDidChangeExeBlock)(__kindof SJBaseVideoPlayer *player);

@property (nonatomic, copy, nullable) void(^presentationSizeDidChangeExeBlock)(__kindof SJBaseVideoPlayer *player);

@property (nonatomic, copy, nullable) void(^playbackTypeDidChangeExeBlock)(__kindof SJBaseVideoPlayer *player);

@property (nonatomic, copy, nullable) void(^screenLockStateDidChangeExeBlock)(__kindof SJBaseVideoPlayer *player);

@property (nonatomic, copy, nullable) void(^mutedDidChangeExeBlock)(__kindof SJBaseVideoPlayer *player);

@property (nonatomic, copy, nullable) void(^playerVolumeDidChangeExeBlock)(__kindof SJBaseVideoPlayer *player);

@property (nonatomic, copy, nullable) void(^rateDidChangeExeBlock)(__kindof SJBaseVideoPlayer *player);

@property (nonatomic, weak, readonly, nullable) __kindof SJBaseVideoPlayer *player;

@property (nonatomic, copy, nullable) void(^didPlayToEndTimeExeBlock)(__kindof SJBaseVideoPlayer *player) __deprecated_msg("use `playbackDidFinishExeBlock`");

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;
@end
NS_ASSUME_NONNULL_END