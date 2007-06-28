/*
 *
 *  Copyright (C) 1996-2004, OFFIS
 *
 *  This software and supporting documentation were developed by
 *
 *    Kuratorium OFFIS e.V.
 *    Healthcare Information and Communication Systems
 *    Escherweg 2
 *    D-26121 Oldenburg, Germany
 *
 *  THIS SOFTWARE IS MADE AVAILABLE,  AS IS,  AND OFFIS MAKES NO  WARRANTY
 *  REGARDING  THE  SOFTWARE,  ITS  PERFORMANCE,  ITS  MERCHANTABILITY  OR
 *  FITNESS FOR ANY PARTICULAR USE, FREEDOM FROM ANY COMPUTER DISEASES  OR
 *  ITS CONFORMITY TO ANY SPECIFICATION. THE ENTIRE RISK AS TO QUALITY AND
 *  PERFORMANCE OF THE SOFTWARE IS WITH THE USER.
 *
 *  Module:  dcmimgle
 *
 *  Author:  Joerg Riesmeier
 *
 *  Purpose: DicomPixel (Header)
 *
 *  Last Update:      $Author: braindead $
 *  Update Date:      $Date: 2005/08/23 19:31:59 $
 *  CVS/RCS Revision: $Revision: 1.1 $
 *  Status:           $State: Exp $
 *
 *  CVS/RCS Log at end of file
 *
 */


#ifndef DIPIXEL_H
#define DIPIXEL_H

#include "osconfig.h"
#include "dctypes.h"

#include "diutils.h"


/*---------------------*
 *  class declaration  *
 *---------------------*/

/** Abstract base class to handle pixel data
 */
class DiPixel
{

 public:

    /** constructor
     *
     ** @param  count       number of pixels stored in the buffer
     *  @param  inputCount  number of pixels read from 'PixelData' attribute
     */
    DiPixel(const unsigned long count,
            const unsigned long inputCount = 0)
      : Count(count),
        InputCount(inputCount)
    {
    }

    /** destructor
     */
    virtual ~DiPixel()
    {
    }

    /** get integer representation (abstract)
     *
     ** @return integer representation
     */
    virtual EP_Representation getRepresentation() const = 0;

    /** get number of planes (abstract)
     *
     ** @return number of planes
     */
    virtual int getPlanes() const = 0;

    /** get pointer to pixel data (abstract)
     *
     ** @return pointer to pixel data
     */
    virtual const void *getData() const = 0;

    /** get pointer to pixel data (abstract)
     *
     ** @return pointer to pixel data
     */
    virtual void *getDataPtr() = 0;

    /** get reference to pointer to pixel data (abstract)
     *
     ** @return reference to pointer to pixel data
     */
    virtual void *getDataArrayPtr() = 0;

    /** get number of pixels
     *
     ** @return number of pixels
     */
    inline unsigned long getCount() const
    {
        return Count;
    }

    /** get number of pixels stored in the 'PixelData' element
     *
     ** @return number pixels read from the input buffer
     */
    inline unsigned long getInputCount() const
    {
        return InputCount;
    }


 protected:

    /// number of pixels
    /*const*/ unsigned long Count;

    /// number of pixels in the input buffer
    unsigned long InputCount;
};


#endif


/*
 *
 * CVS/RCS Log:
 * $Log: dipixel.h,v $
 * Revision 1.1  2005/08/23 19:31:59  braindead
 * - initial savannah import
 *
 * Revision 1.1  2005/06/26 19:26:05  pipelka
 * - added dcmtk
 *
 * Revision 1.9  2004/02/06 11:07:50  joergr
 * Distinguish more clearly between const and non-const access to pixel data.
 *
 * Revision 1.8  2003/12/09 10:07:16  joergr
 * Removed leading underscore characters from preprocessor symbols (reserved
 * symbols). Updated copyright header.
 *
 * Revision 1.7  2002/06/26 16:06:08  joergr
 * Enhanced handling of corrupted pixel data and/or length.
 *
 * Revision 1.6  2001/06/01 15:49:50  meichel
 * Updated copyright header
 *
 * Revision 1.5  2000/03/08 16:24:23  meichel
 * Updated copyright header.
 *
 * Revision 1.4  1999/09/17 12:47:51  joergr
 * Added/changed/completed DOC++ style comments in the header files.
 *
 * Revision 1.3  1999/03/24 17:20:22  joergr
 * Added/Modified comments and formatting.
 *
 * Revision 1.2  1999/01/20 15:12:10  joergr
 * Replaced invocation of getCount() by member variable Count where possible.
 *
 * Revision 1.1  1998/11/27 15:32:37  joergr
 * Added copyright message.
 * Introduced new pixel base class.
 *
 *
 */