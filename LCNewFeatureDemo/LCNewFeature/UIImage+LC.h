//
//  Created by 刘超 on 15/4/30.
//  Copyright (c) 2015年 Leo. All rights reserved.
//
//  Email :  leoios@sina.com
//  GitHub: http://github.com/LeoiOS
//  如有问题或建议请给我发Email, 或在该项目的GitHub主页lssues我, 谢谢:)
//

#import <UIKit/UIKit.h>

@interface UIImage (LC)

/**
 *  初始化一张适配iPhone屏幕尺寸的图片, 类方法
 *
 *  @param imageName 图片名称
 *
 *  @param iphone5 是否有iPhone5的图片, 默认`NO`, 无图片; 有图片请参考命名: `<name>_iphone5`, 如: `Apple_iphone5h@2x.png`
 *
 *  @param iphone6 是否有iPhone6的图片, 默认`NO`, 无图片; 有图片请参考命名: `<name>_iphone6`, 如: `Apple_iphone6@2x.png`
 *
 *  @param iphone6p 是否有iPhone6P的图片, 默认`NO`, 无图片; 有图片请参考命名: `<name>_iphone6p`, 如: `Apple_iphone6p@2x.png`
 */
+ (instancetype)imageNamedForAdaptation:(NSString *)imageName
                                iphone5:(BOOL)iphone5
                                iphone6:(BOOL)iphone6
                               iphone6p:(BOOL)iphone6p;

@end
