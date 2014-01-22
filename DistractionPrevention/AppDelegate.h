//
//  AppDelegate.h
//  DistractionPrevention
//
//  Created by Max Bothe on 20/01/14.
//  Copyright (c) 2014 Jelzin Corp. All rights reserved.
//

#import <Cocoa/Cocoa.h>

@interface AppDelegate : NSObject <NSApplicationDelegate>

@property (nonatomic, strong) IBOutlet NSMenu *statusMenu;
@property (nonatomic, strong) NSStatusItem *statusItem;

@end
