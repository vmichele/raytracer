#ifndef FISHEYE_H
#define FISHEYE_H

#include "Camera.h"
#include "Point2D.h"

class Fisheye: public Camera {

public:
  Fisheye(void);
  Fisheye(const Fisheye& fisheye);
  Fisheye& operator=(const Fisheye& rhs);
  virtual Fisheye* clone(void) const;
  virtual ~Fisheye();

  Vector3D ray_direction(const Point2D& pp, const int hres, const int vres, const float s, float& r_squared);
  virtual void render_scene(const World& w);

  void set_fov(float psi);
  void set_rectangular(bool r);

private:
  float psi_max;    // in degrees
  bool rectangular;   // render corners or not
};

inline void Fisheye::set_fov(float psi) {
  psi_max = 0.5 * psi;
}

inline void Fisheye::set_rectangular(bool r) {
  rectangular = r;
}

#endif // FISHEYE_H
