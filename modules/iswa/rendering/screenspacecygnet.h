/*****************************************************************************************
*                                                                                       *
* OpenSpace                                                                             *
*                                                                                       *
* Copyright (c) 2014-2015                                                               *
*                                                                                       *
* Permission is hereby granted, free of charge, to any person obtaining a copy of this  *
* software and associated documentation files (the "Software"), to deal in the Software *
* without restriction, including without limitation the rights to use, copy, modify,    *
* merge, publish, distribute, sublicense, and/or sell copies of the Software, and to    *
* permit persons to whom the Software is furnished to do so, subject to the following   *
* conditions:                                                                           *
*                                                                                       *
* The above copyright notice and this permission notice shall be included in all copies *
* or substantial portions of the Software.                                              *
*                                                                                       *
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,   *
* INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A         *
* PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT    *
* HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF  *
* CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE  *
* OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.                                         *
****************************************************************************************/

#ifndef __SCREENSPACECYGNET_H__
#define __SCREENSPACECYGNET_H__

#include <chrono>
#include <future>
#include <openspace/rendering/screenspacerenderable.h>
#include <modules/base/rendering/screenspaceimage.h>

#include <openspace/engine/downloadmanager.h>
#include <modules/iswa/util/iswamanager.h>

namespace openspace{

class ScreenSpaceCygnet : public ScreenSpaceImage {
public:
    ScreenSpaceCygnet(const ghoul::Dictionary& dictionary);
    ~ScreenSpaceCygnet();

    virtual void update() override;

private:
    int _cygnetId;

    int _updateInterval;
    double _openSpaceTime;
    double _lastUpdateOpenSpaceTime;

    std::chrono::milliseconds _realTime;
    std::chrono::milliseconds _lastUpdateRealTime;
    int _minRealTimeUpdateInterval;
};

 } // namespace openspace

#endif //__SCREENSPACECYGNET_H__