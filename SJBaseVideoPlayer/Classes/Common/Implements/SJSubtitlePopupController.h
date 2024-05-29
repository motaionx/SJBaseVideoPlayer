
#import <Foundation/Foundation.h>
#import "SJSubtitlePopupControllerDefines.h"
#import "SJSubtitleItem.h"

NS_ASSUME_NONNULL_BEGIN
@interface SJSubtitlePopupController : NSObject<SJSubtitlePopupController>

@property (nonatomic, copy, nullable) NSArray<SJSubtitleItem *> *subtitles;

@property (nonatomic) NSInteger numberOfLines;

@property (nonatomic) UIEdgeInsets contentInsets;

@end
NS_ASSUME_NONNULL_END