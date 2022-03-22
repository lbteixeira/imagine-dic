#pragma once

#include "interpolation.hpp"
#include "mesh.hpp"
#include <memory>

namespace Imagine {
  class Image {
    public:
      Image();

    private:
      std::unique_ptr<Mesh> _mesh;
      std::unique_ptr<Interpolator> _interpolator;
  };
}
