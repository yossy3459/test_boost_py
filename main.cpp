#include <iostream>
#define BOOST_BIND_GLOBAL_PLACEHOLDERS
//placeholdersの衝突を回避するため(要調査)
#include <boost/python/numpy.hpp>
namespace py = boost::python;
namespace np = boost::python::numpy;

py::list add10 (py::list l) {
  py::list x;
  py::list y;

  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++){
      auto z = py::extract<int>(l[i][j]) + 10;
      y.append(z);
    }
    x.append(y);
    y = py::list();
  }
  return x;
}

int main()
{
  Py_Initialize();
  np::initialize();

  py::list l;
  py::list j;
  py::list k;
  j.append(101);
  j.append(202);
  k.append(303);
  k.append(404);
  l.append(j);
  l.append(k);

  auto l_ret = add10(l);

  for (int i=0; i<2; i++) {
    for (int j=0; j<2; j++) {
      std::cout << py::extract<int>(l_ret[i][j]) << ",";
    }
    std::cout << std::endl;
  }

  return 0;
}