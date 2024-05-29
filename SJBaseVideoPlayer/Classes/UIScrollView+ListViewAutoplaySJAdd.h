
#import <UIKit/UIKit.h>
#import "SJPlayerAutoplayConfig.h"

NS_ASSUME_NONNULL_BEGIN

@interface UIScrollView (ListViewAutoplaySJAdd)

@property (nonatomic, readonly) BOOL sj_enabledAutoplay;

- (void)sj_enableAutoplayWithConfig:(SJPlayerAutoplayConfig *)autoplayConfig;

- (void)sj_disableAutoplay;

- (void)sj_removeCurrentPlayerView;
@end


@interface UIScrollView (SJAutoplayPlayerAssigns)
@property (nonatomic, strong, nullable, readonly) NSIndexPath *sj_currentPlayingIndexPath;
- (void)setSj_currentPlayingIndexPath:(nullable NSIndexPath *)sj_currentPlayingIndexPath;
@end
NS_ASSUME_NONNULL_END