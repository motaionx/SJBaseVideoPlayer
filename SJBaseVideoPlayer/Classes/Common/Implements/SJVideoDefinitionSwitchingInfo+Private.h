
#import "SJVideoDefinitionSwitchingInfo.h"

NS_ASSUME_NONNULL_BEGIN

@interface SJVideoDefinitionSwitchingInfo (Private)
@property (nonatomic, weak, nullable) SJVideoPlayerURLAsset *currentPlayingAsset;

@property (nonatomic, weak, nullable) SJVideoPlayerURLAsset *switchingAsset;

@property (nonatomic) SJDefinitionSwitchStatus status;
@end

NS_ASSUME_NONNULL_END