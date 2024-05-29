
#import "SJVideoPlayerURLAsset.h"
#import "SJSubtitleItem.h"

NS_ASSUME_NONNULL_BEGIN

@interface SJVideoPlayerURLAsset (SJSubtitlesAdd)
@property (nonatomic, copy, nullable) NSArray<SJSubtitleItem *> *subtitles;

@end

NS_ASSUME_NONNULL_END