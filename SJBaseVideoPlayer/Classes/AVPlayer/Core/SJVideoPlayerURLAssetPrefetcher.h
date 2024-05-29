
#import <Foundation/Foundation.h>
#import "SJVideoPlayerURLAsset.h"

NS_ASSUME_NONNULL_BEGIN
typedef NSInteger SJPrefetchIdentifier;

@interface SJVideoPlayerURLAssetPrefetcher : NSObject
+ (instancetype)shared;
@property (nonatomic) NSUInteger maxCount; // default value is 3;

- (SJPrefetchIdentifier)prefetchAsset:(SJVideoPlayerURLAsset *)asset;
- (SJVideoPlayerURLAsset *_Nullable)assetForURL:(NSURL *)URL;
- (SJVideoPlayerURLAsset *_Nullable)assetForIdentifier:(SJPrefetchIdentifier)identifier;
- (void)removeAsset:(SJVideoPlayerURLAsset *)asset;
@end
NS_ASSUME_NONNULL_END