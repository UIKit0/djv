//------------------------------------------------------------------------------
// Copyright (c) 2004-2012 Darby Johnston
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
// * Redistributions of source code must retain the above copyright notice,
//   this list of conditions, and the following disclaimer.
//
// * Redistributions in binary form must reproduce the above copyright notice,
//   this list of conditions, and the following disclaimer in the documentation
//   and/or other materials provided with the distribution.
//
// * Neither the names of the copyright holders nor the names of any
//   contributors may be used to endorse or promote products derived from this
//   software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
// SUBSTITUE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE.
//------------------------------------------------------------------------------

//! \file djv_lut_load.h

#ifndef DJV_LUT_LOAD_H
#define DJV_LUT_LOAD_H

#include <djv_lut.h>

namespace djv_lut
{
using namespace djv;

//------------------------------------------------------------------------------
//! \class Load
//!
//! This class provides a load plugin.
//------------------------------------------------------------------------------

class Load : public Image_Load
{
public:

    //! Options.

    enum OPTIONS
    {
        FORMAT_OPTION,
        TYPE_OPTION,

        _OPTIONS_SIZE
    };

    //! Get the option labels.

    static const List<String> & label_options();

    //! This struct provides options.

    struct Options
    {
        //! Constructor.

        Options();

        FORMAT format;
        TYPE   type;
    };

    virtual Plugin * copy() const;

    virtual String name() const;

    virtual List<String> extensions() const;

    virtual bool option(const String &, String *);

    virtual String option(const String &) const;

    virtual List<String> options() const;

    virtual void open(const File &, Image_Io_Info &) throw (Error);

    virtual void load(Image &, const Image_Io_Frame_Info &) throw (Error);

private:

    void _open(const File &, Image_Io_Info &) throw (Error);

    Options _options;
    File    _file;
    File_Io _io;
    FORMAT  _format;
};

} // djv_lut

#endif // DJV_LUT_LOAD_H

