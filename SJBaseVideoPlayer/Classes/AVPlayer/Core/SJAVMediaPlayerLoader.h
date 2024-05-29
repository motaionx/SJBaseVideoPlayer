
#import <Foundation/Foundation.h>
#import "SJVideoPlayerURLAsset.h"
#import "SJAVMediaPlayer.h"

NS_ASSUME_NONNULL_BEGIN
@interface SJAVMediaPlayerLoader : NSObject

+ (nullable SJAVMediaPlayer *)loadPlayerForMedia:(SJVideoPlayerURLAsset *)media;

+ (void)clearPlayerForMedia:(SJVideoPlayerURLAsset *)media;

@end
NS_ASSUME_NONNULL_END