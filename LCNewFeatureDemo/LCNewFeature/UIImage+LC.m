//
//  Created by 刘超 on 15/4/30.
//  Copyright (c) 2015年 Leo. All rights reserved.
//
//  Email :  leoios@sina.com
//  GitHub: http://github.com/LeoiOS
//  如有问题或建议请给我发Email, 或在该项目的GitHub主页lssues我, 谢谢:)
//

#import "UIImage+LC.h"

#define IPHONE5 ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(640, 1136), [[UIScreen mainScreen] currentMode].size) : NO)
#define IPHONE6 ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(750, 1334), [[UIScreen mainScreen] currentMode].size) : NO)
#define IPHONE6P ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(1242, 2208), [[UIScreen mainScreen] currentMode].size) : NO)

@implementation UIImage (LC)

+ (instancetype)imageNamedForAdaptation:(NSString *)imageName
                                iphone5:(BOOL)iphone5
                                iphone6:(BOOL)iphone6
                               iphone6p:(BOOL)iphone6p {
    
    NSString *realImageName = imageName;
    
    // 当前设备是iPhone5\iPhone5S
    if (IPHONE5 && iphone5) {
        
        realImageName = [NSString stringWithFormat:@"%@_iphone5", realImageName];
    }
    
    // 当前设备是iPhone6
    if (IPHONE6 && iphone6) {
        
        realImageName = [NSString stringWithFormat:@"%@_iphone6", realImageName];
    }
    
    // 当前设备是iPhone6P
    if (IPHONE6P && iphone6p) {
        
        realImageName = [NSString stringWithFormat:@"%@_iphone6p", realImageName];
    }
    
    return [self imageNamed:realImageName];
}

@end
