
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
@protocol SJPlayerAutoplayDelegate;

@interface SJPlayerAutoplayConfig : NSObject
+ (instancetype)configWithPlayerSuperviewSelector:(nullable SEL)playerSuperviewSelector autoplayDelegate:(id<SJPlayerAutoplayDelegate>)delegate;

@property (nonatomic, nullable) SEL playerSuperviewSelector;

@property (nonatomic, weak, nullable, readonly) id<SJPlayerAutoplayDelegate> autoplayDelegate;

@property (nonatomic) UICollectionViewScrollDirection scrollDirection;

@property (nonatomic) UIEdgeInsets playableAreaInsets;
@end

@protocol SJPlayerAutoplayDelegate <NSObject>
- (void)sj_playerNeedPlayNewAssetAtIndexPath:(NSIndexPath *)indexPath;
@end



@interface SJPlayerAutoplayConfig (SJDeprecated)
+ (instancetype)configWithAutoplayDelegate:(id<SJPlayerAutoplayDelegate>)autoplayDelegate  __deprecated_msg("use `configWithPlayerSuperviewSelector:autoplayDelegate:`;");
+ (instancetype)configWithPlayerSuperviewTag:(NSInteger)playerSuperviewTag
                            autoplayDelegate:(id<SJPlayerAutoplayDelegate>)autoplayDelegate __deprecated_msg("use `configWithPlayerSuperviewSelector:autoplayDelegate:`;");
@property (nonatomic, readonly) NSInteger playerSuperviewTag __deprecated_msg("use `config.scrollViewSelector`");
@end
NS_ASSUME_NONNULL_END