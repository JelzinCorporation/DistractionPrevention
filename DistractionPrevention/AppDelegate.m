//
//  AppDelegate.m
//  DistractionPrevention
//
//  Created by Max Bothe on 20/01/14.
//  Copyright (c) 2014 Jelzin Corp. All rights reserved.
//

#import "AppDelegate.h"

@implementation AppDelegate

- (void)applicationDidFinishLaunching:(NSNotification *)aNotification
{
    // Insert code here to initialize your application
}

-(void)awakeFromNib
{
    [super awakeFromNib];

    NSImage *image = [NSImage imageNamed:@"distrprev"];
    NSImage *highlightImage = [NSImage imageNamed:@"distrprev_highlight"];
    self.statusItem = [[NSStatusBar systemStatusBar] statusItemWithLength:NSSquareStatusItemLength];
    self.statusItem.menu = self.statusMenu;
    self.statusItem.image = image;
    self.statusItem.alternateImage = highlightImage;
    self.statusItem.highlightMode = YES;
    self.statusItem.toolTip = @"Distraction Prevention v0.1";
}

@end
