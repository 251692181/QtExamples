/*=========================================================================
 *
 *  Copyright David Doria 2011 daviddoria@gmail.com
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *         http://www.apache.org/licenses/LICENSE-2.0.txt
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 *=========================================================================*/

#ifndef HELPERS_H
#define HELPERS_H

// Custom
#include "Types.h"

// ITK
#include "itkConstNeighborhoodIterator.h"
#include "itkImageRegionIterator.h"
#include "itkImageFileWriter.h"
#include "itkNeighborhoodIterator.h"
#include "itkPasteImageFilter.h"
#include "itkMinimumMaximumImageCalculator.h"
#include "itkRegionOfInterestImageFilter.h"
#include "itkRescaleIntensityImageFilter.h"

// VTK
class vtkImageData;

namespace Helpers
{
  
  
template<typename TImage>
void DeepCopy(typename TImage::Pointer input, typename TImage::Pointer output);

template<typename TImage>
void DeepCopyVectorImage(typename TImage::Pointer input, typename TImage::Pointer output);

void ITKImagetoVTKImage(FloatVectorImageType::Pointer image, vtkImageData* outputImage); // This function simply drives ITKImagetoVTKRGBImage or ITKImagetoVTKMagnitudeImage
void ITKImagetoVTKRGBImage(FloatVectorImageType::Pointer image, vtkImageData* outputImage);
void ITKImagetoVTKMagnitudeImage(FloatVectorImageType::Pointer image, vtkImageData* outputImage);

itk::Index<2> GetRegionCenter(itk::ImageRegion<2> region);

template <typename TDebugImageType>
void DebugWriteImage(typename TDebugImageType::Pointer image, std::string filePrefix, unsigned int iteration);

template <class T>
void WriteScaledScalarImage(typename T::Pointer image, std::string filename);

template <class T>
void CopyPatch(typename T::Pointer sourceImage, typename T::Pointer targetImage, itk::Index<2> sourcePosition, itk::Index<2> targetPosition, unsigned int radius);

template <class T>
void CreateConstantPatch(typename T::Pointer patch, typename T::PixelType value, unsigned int radius);

template<typename T>
void ReplaceValue(typename T::Pointer image, typename T::PixelType queryValue, typename T::PixelType replacementValue);

template<typename T>
void WriteImage(typename T::Pointer image, std::string filename);

template <class T>
void CopyPatchIntoImage(typename T::Pointer patch, typename T::Pointer image, itk::Index<2> position);

template <class T>
void CreateBlankPatch(typename T::Pointer patch, unsigned int radius);

template <class T>
void CopySelfPatchIntoValidRegion(typename T::Pointer image, const UnsignedCharScalarImageType::Pointer mask,
                                  itk::ImageRegion<2> sourceRegion, itk::ImageRegion<2> destinationRegion);

template <class T>
float MaxValue(typename T::Pointer image);

template <class T>
float MaxValueLocation(typename T::Pointer image);

template <class T>
float MinValue(typename T::Pointer image);

template <class T>
itk::Index<2> MinValueLocation(typename T::Pointer image);

template <typename TImage>
void ColorToGrayscale(typename TImage::Pointer colorImage, UnsignedCharScalarImageType::Pointer grayscaleImage);

// Non template function declarations
itk::ImageRegion<2> GetRegionInRadiusAroundPixel(itk::Index<2> pixel, unsigned int radius);

template <typename TPixelType>
double PixelSquaredDifference(TPixelType, TPixelType);

bool IsValidPatch(const UnsignedCharScalarImageType::Pointer mask, itk::ImageRegion<2> region);

}// end namespace

#include "Helpers.txx"

#endif