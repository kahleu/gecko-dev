/* -*- Mode: C++; tab-width: 2; indent-tabs-mode: nil; c-basic-offset: 2 -*-
 *
 * The contents of this file are subject to the Netscape Public License
 * Version 1.0 (the "NPL"); you may not use this file except in
 * compliance with the NPL.  You may obtain a copy of the NPL at
 * http://www.mozilla.org/NPL/
 *
 * Software distributed under the NPL is distributed on an "AS IS" basis,
 * WITHOUT WARRANTY OF ANY KIND, either express or implied. See the NPL
 * for the specific language governing rights and limitations under the
 * NPL.
 *
 * The Initial Developer of this code under the NPL is Netscape
 * Communications Corporation.  Portions created by Netscape are
 * Copyright (C) 1998 Netscape Communications Corporation.  All Rights
 * Reserved.
 */
#include "nsImageMac.h"
#include "nsRenderingContextMac.h"
#include "nsDeviceContextMac.h"

#include "nspr.h"

#define IsFlagSet(a,b) (a & b)

static NS_DEFINE_IID(kIImageIID, NS_IIMAGE_IID);

//------------------------------------------------------------

nsImageMac :: nsImageMac()
{
/*  printf("[[[[[[[[[[[[[[[[[[[[ New Image Created ]]]]]]]]]]]]]]]]]]]]]]\n");
  NS_INIT_REFCNT();
  mImage = nsnull ;
  mImageBits = nsnull;
  mConvertedBits = nsnull;
  mBitsForCreate = nsnull;
  mWidth = 0;
  mHeight = 0;
  mDepth = 0;
  mOriginalDepth = 0;
  mColorMap = nsnull;*/
}

//------------------------------------------------------------

nsImageMac :: ~nsImageMac()
{
/*  if (nsnull != mImage) {
    XDestroyImage(mImage);
    mImage = nsnull;
  }
  if(nsnull != mConvertedBits) 
    {
    delete[] (PRUint8*)mConvertedBits;
    mConvertedBits = nsnull;
    }

  if(nsnull != mImageBits)
    {
    delete[] (PRUint8*)mImageBits;
    mImageBits = nsnull;
    }
  if(nsnull!= mColorMap)
    delete mColorMap;*/
}

NS_IMPL_ISUPPORTS(nsImageMac, kIImageIID);

//------------------------------------------------------------

nsresult nsImageMac :: Init(PRInt32 aWidth, PRInt32 aHeight, PRInt32 aDepth,nsMaskRequirements aMaskRequirements)
{
/*  if(nsnull != mImageBits)
    delete[] (PRUint8*)mImageBits;

  if(nsnull != mColorMap)
    delete[] mColorMap;

  if (nsnull != mImage) {
    XDestroyImage(mImage);
    mImage = nsnull;
  }
  mWidth = aWidth;
  mHeight = aHeight;
  mDepth = aDepth;
  mOriginalDepth = aDepth;
  mOriginalRowBytes = CalcBytesSpan(aWidth);
  mConverted = PR_FALSE;

  ComputePaletteSize(aDepth);

  // create the memory for the image
  ComputMetrics();

  mImageBits = (PRUint8*) new PRUint8[mSizeImage]; 

  mColorMap = new nsColorMap;

  if (mColorMap != nsnull)
    {
    mColorMap->NumColors = mNumPalleteColors;
    mColorMap->Index = new PRUint8[3 * mNumPalleteColors];
    memset(mColorMap->Index, 0, sizeof(PRUint8) * (3 * mNumPalleteColors));
    }
*/
  return NS_OK;
}

//------------------------------------------------------------

/*void nsImageMac::ComputMetrics()
{

  mRowBytes = CalcBytesSpan(mWidth);
  mSizeImage = mRowBytes * mHeight;

}*/

//------------------------------------------------------------

// figure out how big our palette needs to be
/*void nsImageMac :: ComputePaletteSize(PRIntn nBitCount)
{
  switch (nBitCount)
    {
    case 8:
      mNumPalleteColors = 256;
      mNumBytesPixel = 1;
      break;
    case 16:
      mNumPalleteColors = 0;
      mNumBytesPixel = 2;
      break;
    case 24:
      mNumPalleteColors = 0;
      mNumBytesPixel = 3;
      break;
    default:
      mNumPalleteColors = -1;
      mNumBytesPixel = 0;
      break;
    }
}*/

//------------------------------------------------------------

PRInt32  nsImageMac :: CalcBytesSpan(PRUint32  aWidth)
{
/*PRInt32 spanbytes;

  spanbytes = (aWidth * mDepth) >> 5;

  if (((PRUint32)aWidth * mDepth) & 0x1F) 
    spanbytes++;
  spanbytes <<= 2;
  return(spanbytes);*/
  return 0;
}

//------------------------------------------------------------

// set up the pallete to the passed in color array, RGB only in this array
void nsImageMac :: ImageUpdated(nsIDeviceContext *aContext, PRUint8 aFlags, nsRect *aUpdateRect)
{

  /*if (nsnull == mImage)
    return;

  if (IsFlagSet(nsImageUpdateFlags_kBitsChanged, aFlags)){
  }
*/
}


//------------------------------------------------------------

// Draw the bitmap, this method has a source and destination coordinates
PRBool nsImageMac :: Draw(nsIRenderingContext &aContext, nsDrawingSurface aSurface, PRInt32 aSX, PRInt32 aSY, PRInt32 aSWidth, PRInt32 aSHeight,
                          PRInt32 aDX, PRInt32 aDY, PRInt32 aDWidth, PRInt32 aDHeight)
{
/*nsDrawingSurfaceMac	*Macdrawing =(nsDrawingSurfaceMac*) aSurface;
 
  if (nsnull == mImage)
    return PR_FALSE;

  XPutImage(Macdrawing->display,Macdrawing->drawable,Macdrawing->gc,mImage,
                    aSX,aSY,aDX,aDY,aDWidth,aDHeight);  
*/
  return PR_TRUE;
}

//------------------------------------------------------------

// Draw the bitmap, this draw just has destination coordinates
PRBool nsImageMac :: Draw(nsIRenderingContext &aContext, 
                       nsDrawingSurface aSurface,
                       PRInt32 aX, PRInt32 aY, 
                       PRInt32 aWidth, PRInt32 aHeight)
{
/*nsDrawingSurfaceMac	*Macdrawing =(nsDrawingSurfaceMac*) aSurface;

    mImage = nsnull;
    Optimize(aSurface);
 
  if (nsnull == mImage)
    return PR_FALSE;
  XPutImage(Macdrawing->display,Macdrawing->drawable,Macdrawing->gc,mImage,
                    0,0,aX,aY,aWidth,aHeight);  */
  return PR_TRUE;
}

//------------------------------------------------------------

void nsImageMac::CompositeImage(nsIImage *aTheImage, nsPoint *aULLocation,nsBlendQuality aBlendQuality)
{

}

//------------------------------------------------------------

// lets build an alpha mask from this image
PRBool nsImageMac::SetAlphaMask(nsIImage *aTheMask)
{
  return(PR_FALSE);
}


void nsImageMac::AllocConvertedBits(PRUint32 aSize)
{
  /*if (nsnull == mConvertedBits)
    mConvertedBits = (PRUint8*) new PRUint8[aSize]; */
}

//------------------------------------------------------------

void nsImageMac::ConvertImage(nsDrawingSurface aDrawingSurface)
{
/*nsDrawingSurfaceMac	*Macdrawing =(nsDrawingSurfaceMac*) aDrawingSurface;
PRUint8                 *tempbuffer,*cursrc,*curdest;
PRInt32                 x,y;
PRUint16                red,green,blue,*cur16;

  mBitsForCreate = mImageBits;

  if((Macdrawing->depth==24) &&  (mOriginalDepth==8))
    {
    // convert this nsImage to a 24 bit image
    mDepth = 24;
    ComputePaletteSize(mDepth);
    ComputMetrics();
    AllocConvertedBits(mSizeImage);
    tempbuffer = mConvertedBits;
    mBitsForCreate = mConvertedBits;

    for(y=0;y<mHeight;y++)
      {
      cursrc = mImageBits+(y*mOriginalRowBytes);
      curdest =tempbuffer+(y*mRowBytes);
      for(x=0;x<mOriginalRowBytes;x++)
        {
        *curdest = mColorMap->Index[(3*(*cursrc))+2];  // red
        curdest++;
        *curdest = mColorMap->Index[(3*(*cursrc))+1];  // green
        curdest++;
        *curdest = mColorMap->Index[(3*(*cursrc))];  // blue
        curdest++;
        cursrc++;
        } 
      }
   
#if 0 
    if(mColorMap)
      delete mColorMap;

    // after we are finished converting the image, build a new color map   
    mColorMap = new nsColorMap;

    if (mColorMap != nsnull)
      {
      mColorMap->NumColors = mNumPalleteColors;
      mColorMap->Index = new PRUint8[3 * mNumPalleteColors];
      memset(mColorMap->Index, 0, sizeof(PRUint8) * (3 * mNumPalleteColors));
      }
#endif
    }
 
  // convert the 8 bit image to 16 bit
  if((Macdrawing->depth==16) && (mOriginalDepth==8))
    {
    mDepth = 16;
    ComputePaletteSize(mDepth);
    ComputMetrics();
    AllocConvertedBits(mSizeImage);
    tempbuffer = mConvertedBits;
    mBitsForCreate = mConvertedBits;

    for(y=0;y<mHeight;y++)
      {
      cursrc = mImageBits+(y*mOriginalRowBytes);
      cur16 = (PRUint16*) (tempbuffer+(y*mRowBytes));

      for(x=0;x<mOriginalRowBytes;x++)
        {
        blue = mColorMap->Index[(3*(*cursrc))+2];  // red
        green = mColorMap->Index[(3*(*cursrc))+1];  // green
        red = mColorMap->Index[(3*(*cursrc))];  // blue
        cursrc++;
        *cur16 = ((red&0xf8)<<8)|((green&0xfc)<<3)| ((blue&0xf8)>>3);	
        cur16++;
        } 
      }
   
#if 0
    if (mColorMap != nsnull)
      {
      mColorMap->NumColors = mNumPalleteColors;
      mColorMap->Index = new PRUint8[3 * mNumPalleteColors];
      memset(mColorMap->Index, 0, sizeof(PRUint8) * (3 * mNumPalleteColors));
      }
#endif
    }
*/
}

//------------------------------------------------------------

nsresult nsImageMac::Optimize(nsDrawingSurface aDrawingSurface)
{
/*PRInt16 i;

  if (nsnull == mImage)
    {
    ConvertImage(aDrawingSurface);
    CreateImage(aDrawingSurface);
    }*/
  return NS_OK;
}

//------------------------------------------------------------

void nsImageMac::CreateImage(nsDrawingSurface aSurface)
{
/*  PRUint32 wdepth;
  Visual * visual ;
  PRUint32 format ;
  nsDrawingSurfaceMac	*Macdrawing =(nsDrawingSurfaceMac*) aSurface;
  
  if(mImageBits) {
    if (Macdrawing->visual->c_class == TrueColor || 
        Macdrawing->visual->c_class == DirectColor) 
      {
      format = ZPixmap;
      } 
    else 
      {
      format = XYPixmap;
      }

    mImage = ::XCreateImage(Macdrawing->display,
			    Macdrawing->visual,
			    Macdrawing->depth,
			    format,
			    0,
			    (char *)mBitsForCreate,
			    (unsigned int)mWidth, 
			    (unsigned int)mHeight,
			    32,mRowBytes);

    mImage->byte_order       = ImageByteOrder(Macdrawing->display);
    mImage->bits_per_pixel   = Macdrawing->depth;
    mImage->bitmap_bit_order = BitmapBitOrder(Macdrawing->display);
    mImage->bitmap_unit      = 32;

  }	
  return ;*/
}
