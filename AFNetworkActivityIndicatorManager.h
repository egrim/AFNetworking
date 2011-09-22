// AFNetworkActivityIndicatorManager.h
//
// Copyright (c) 2011 Gowalla (http://gowalla.com/)
// 
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
// 
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

#import <Foundation/Foundation.h>

/**
 `AFNetworkActivityIndicatorManager` manages the state of the network activity indicator in the status bar. When network operations start, they can call `-incrementActivityCount`, and once they're finished, call `-decrementActivityCount`. The number of active requests is incremented and decremented much like a stack or a semaphore, and the activity indicator will animate so long as that number is greater than zero.
 */
@interface AFNetworkActivityIndicatorManager : NSObject {
@private
	NSInteger _activityCount;
}

/**
 Returns the shared network activity indicator manager object for the system.
 
 @return The systemwide network activity indicator manager.
 */
+ (AFNetworkActivityIndicatorManager *)sharedManager;

/**
 Increments the number of active network requests. If this number was zero before incrementing, this will start animating the status bar network activity indicator.
 */
- (void)incrementActivityCount;

/**
 Decrements the number of active network requests. If this number becomes zero before decrementing, this will stop animating the status bar network activity indicator.
 */
- (void)decrementActivityCount;

@end
