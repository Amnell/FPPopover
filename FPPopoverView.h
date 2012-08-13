//
//  FPPopoverView.h
//
//  Created by Alvise Susmel on 1/4/12.
//  Copyright (c) 2012 Fifty Pixels Ltd. All rights reserved.
//
//  https://github.com/50pixels/FPPopover


#import <UIKit/UIKit.h>
#import <QuartzCore/QuartzCore.h>

typedef enum {
    FPPopoverArrowDirectionUp = 1UL << 0,
    FPPopoverArrowDirectionDown = 1UL << 1,
    FPPopoverArrowDirectionLeft = 1UL << 2,
    FPPopoverArrowDirectionRight = 1UL << 3,

    FPPopoverArrowDirectionVertical = FPPopoverArrowDirectionUp | FPPopoverArrowDirectionDown,
    FPPopoverArrowDirectionHorizontal = FPPopoverArrowDirectionLeft | FPPopoverArrowDirectionRight,
    
    FPPopoverArrowDirectionAny = FPPopoverArrowDirectionUp | FPPopoverArrowDirectionDown | 
    FPPopoverArrowDirectionLeft | FPPopoverArrowDirectionRight
    
} FPPopoverArrowDirection;


#define FPPopoverArrowDirectionIsVertical(direction)    ((direction) == FPPopoverArrowDirectionVertical || (direction) == FPPopoverArrowDirectionUp || (direction) == FPPopoverArrowDirectionDown)

#define FPPopoverArrowDirectionIsHorizontal(direction)    ((direction) == FPPopoverArrowDirectionHorizontal || (direction) == FPPopoverArrowDirectionLeft || (direction) == FPPopoverArrowDirectionRight)


typedef enum {
    FPPopoverTintBlack = 1UL << 0, // default
    FPPopoverTintLightGray = 1UL << 1,
    FPPopoverTintGreen = 1UL << 2,
    FPPopoverTintRed = 1UL << 3,
    FPPopoverTintWhite = 1UL << 4,
    FPPopoverTintDefault = FPPopoverTintBlack
} FPPopoverTint;

typedef enum {
    FPPopoverContentBorderDefault = 1UL << 0, // default
    FPPopoverContentBorderNone = 1UL << 1
} FPPopoverContentBorder;

@interface FPPopoverView : UIView
{
    //default FPPopoverArrowDirectionUp
    FPPopoverArrowDirection _arrowDirection;
    UIView *_contentView;
    UILabel *_titleLabel;
}
@property(nonatomic,strong) NSString *title;
@property(nonatomic) CGPoint relativeOrigin;
@property(nonatomic) FPPopoverTint tint;
@property(nonatomic) FPPopoverContentBorder contentBorder;

-(void)setArrowDirection:(FPPopoverArrowDirection)arrowDirection;
-(FPPopoverArrowDirection)arrowDirection;

-(void)addContentView:(UIView*)contentView;

@end
