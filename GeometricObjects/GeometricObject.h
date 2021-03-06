#ifndef __GEOMETRIC_OBJECT__
#define __GEOMETRIC_OBJECT__

class Material;

#include "Point3D.h"
#include "Ray.h"
#include "ShadeRec.h"
#include "Constants.h"
#include "BBox.h"

#include <QString>

//----------------------------------------------------------------------------------------------------- Class GeometricObject

class GeometricObject {

public:

  GeometricObject(void);                                    // default constructor
  GeometricObject(const GeometricObject& object);           // copy constructor
  virtual GeometricObject* clone(void) const = 0;           // virtual copy constructor
  virtual ~GeometricObject (void);                          // destructor

  virtual bool hit(const Ray& ray, double& t, ShadeRec& s) const = 0;

  Material* get_material(void) const;
  virtual void set_material(Material* mPtr);                // needs to virtual so that it can be overriden in Compound
  void set_shadows(bool b);

  virtual BBox get_bounding_box(void) const;
  virtual bool shadow_hit(const Ray& ray, float& tmin) const;

  virtual Point3D sample(void);
  virtual Normal get_normal(const Point3D& p);
  virtual float pdf(const ShadeRec& sr);

  virtual QString bbox_str(void) const {
    BBox bb = get_bounding_box();
    return QString::number(bb.x0) + " " + QString::number(bb.x1) + " "
         + QString::number(bb.y0) + " " + QString::number(bb.y1) + " "
         + QString::number(bb.z0) + " " + QString::number(bb.z1) + " ";
  }

protected:
  mutable Material* material_ptr;                           // mutable allows Compound::hit, Instance::hit and Grid::hit to assign to material_ptr. hit functions are const
  bool shadows;                                             // cast shadows or not

  GeometricObject& operator= (const GeometricObject& rhs);  // assignment operator
};


// ------------------------------------------------------------------------- get_material

inline Material*
GeometricObject::get_material(void) const {
  return material_ptr;
}

inline BBox GeometricObject::get_bounding_box(void) const {
  return BBox();
}

inline void GeometricObject::set_shadows(bool b) {
  shadows = b;
}

#endif
