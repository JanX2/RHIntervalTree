//
//  RHIntervalTree.h
//  RHIntervalTree
//
//  Created by Richard Heard on 28/02/13.
//  Copyright (c) 2013 Richard Heard. All rights reserved.
//
//  Redistribution and use in source and binary forms, with or without
//  modification, are permitted provided that the following conditions
//  are met:
//  1. Redistributions of source code must retain the above copyright
//  notice, this list of conditions and the following disclaimer.
//  2. Redistributions in binary form must reproduce the above copyright
//  notice, this list of conditions and the following disclaimer in the
//  documentation and/or other materials provided with the distribution.
//  3. The name of the author may not be used to endorse or promote products
//  derived from this software without specific prior written permission.
//
//  THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
//  IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
//  OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
//  IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
//  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
//  NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
//  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
//  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
//  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
//  THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//

// An Objective-C implementation of a Centred Interval Tree.
//
// The tree can be used to efficiently find a set of numeric intervals
// overlapping or containing another interval, for example a view containing
// overlapping calendar events for a given day or week.


#import <Foundation/Foundation.h>


@protocol RHIntervalProtocol <NSObject>

@required
@property (nonatomic, readonly) NSInteger start;
@property (nonatomic, readonly) NSInteger stop;

@end


@interface RHIntervalTree : NSObject

-(instancetype)initWithIntervalObjects:(NSArray*)intervals NS_DESIGNATED_INITIALIZER; //all added objects should implement the RHIntervalProtocol

@property (nonatomic, readonly) NSInteger minStart;
@property (nonatomic, readonly) NSInteger maxStop;

@property (nonatomic, readonly, copy) NSArray *allObjects;

//Contained methods return objects fully contained within the start and stop(inclusive) coordinates.
-(NSArray*)containedObjectsInRange:(NSRange)range;
-(NSArray*)containedObjectsBetweenStart:(NSInteger)start andStop:(NSInteger)stop;

//Overlapping methods return objects which are contained or partially overlap the start and stop(inclusive) coordinates.
-(NSArray*)overlappingObjectsInRange:(NSRange)range;
-(NSArray*)overlappingObjectsBetweenStart:(NSInteger)start andStop:(NSInteger)stop;

@end


//convenience object that implements the RHIntervalProtocol
@interface RHInterval : NSObject <RHIntervalProtocol>

@property (nonatomic, readonly) id<NSObject> object;
@property (nonatomic, readonly) NSRange range;

+(instancetype)intervalWithRange:(NSRange)range object:(id<NSObject>)object;
+(instancetype)intervalWithStart:(NSInteger)start stop:(NSInteger)stop object:(id<NSObject>)object;

-(instancetype)initWithStart:(NSInteger)start stop:(NSInteger)stop object:(id<NSObject>)object NS_DESIGNATED_INITIALIZER;

@end

