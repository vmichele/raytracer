#ifndef __BRDF__
#define __BRDF__

// This file contains the declaration of the base class BRDF

#include <math.h>

#include "RGBColor.h"
#include "Vector3D.h"
#include "ShadeRec.h"
#include "Sampler.h"

class BRDF {

public:
  BRDF(void);
  BRDF(const BRDF& object);
  virtual BRDF* clone(void) const = 0;
  virtual ~BRDF(void);

  virtual RGBColor f(const ShadeRec& sr, const Vector3D& wo, const Vector3D& wi) const;
  virtual RGBColor sample_f(const ShadeRec& sr, const Vector3D& wo, Vector3D& wi) const;
  virtual RGBColor sample_f(const ShadeRec& sr, const Vector3D& wo, Vector3D& wi, float& pdf) const;
  virtual RGBColor rho(const ShadeRec& sr, const Vector3D& wo) const;

  virtual void set_sampler(Sampler* sp);

protected:
  BRDF& operator= (const BRDF& rhs);

protected:
  Sampler* sampler_ptr;
};

#endif
