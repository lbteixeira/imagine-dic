#pragma once

#include "interpolation.hpp"
#include "mesh.hpp"
#include <memory>

namespace Imagine {
  namespace Core {
    class Image {
      public:
        Image();

      private:
        std::unique_ptr<Mesh::Mesh> _mesh;
        std::unique_ptr<Interpolator> _interpolator;
    };
  }
}
