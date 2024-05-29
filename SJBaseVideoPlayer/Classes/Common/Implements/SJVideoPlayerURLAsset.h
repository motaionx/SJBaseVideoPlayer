
#import <UIKit/UIKit.h>
#import "SJPlayModel.h"
#import "SJVideoPlayerPlaybackControllerDefines.h"

@protocol SJVideoPlayerURLAssetObserver;

NS_ASSUME_NONNULL_BEGIN

@interface SJVideoPlayerURLAsset : NSObject<SJMediaModelProtocol>
- (nullable instancetype)initWithURL:(NSURL *)URL startPosition:(NSTimeInterval)startPosition playModel:(__kindof SJPlayModel *)playModel;
- (nullable instancetype)initWithURL:(NSURL *)URL startPosition:(NSTimeInterval)startPosition;
- (nullable instancetype)initWithURL:(NSURL *)URL playModel:(__kindof SJPlayModel *)playModel;
- (nullable instancetype)initWithURL:(NSURL *)URL;

@property (nonatomic) NSTimeInterval startPosition;

@property (nonatomic) NSTimeInterval trialEndPosition;

@property (nonatomic, strong, null_resettable) SJPlayModel *playModel;
- (id<SJVideoPlayerURLAssetObserver>)getObserver;

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;
@property (nonatomic) BOOL isM3u8;
@end


@protocol SJVideoPlayerURLAssetObserver <NSObject>
@property (nonatomic, copy, nullable) void(^playModelDidChangeExeBlock)(SJVideoPlayerURLAsset *asset);
@end
NS_ASSUME_NONNULL_END