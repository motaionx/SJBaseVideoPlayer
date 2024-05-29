
#import "SJVideoPlayerURLAsset+SJSubtitlesAdd.h"
#import <objc/message.h>

NS_ASSUME_NONNULL_BEGIN
@implementation SJVideoPlayerURLAsset (SJSubtitlesAdd)
- (void)setSubtitles:(nullable NSArray<SJSubtitleItem *> *)subtitles {
    objc_setAssociatedObject(self, @selector(subtitles), subtitles, OBJC_ASSOCIATION_COPY_NONATOMIC);
}

- (nullable NSArray<SJSubtitleItem *> *)subtitles {
    return objc_getAssociatedObject(self, _cmd);
}
@end
NS_ASSUME_NONNULL_END