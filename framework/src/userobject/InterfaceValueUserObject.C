//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html

#include "InterfaceValueUserObject.h"
#include "InterfaceValueTools.h"

template <>
InputParameters
validParams<InterfaceValueUserObject>()
{
  InputParameters params = validParams<InterfaceUserObject>();
  params.addParam<MooseEnum>("interface_value_type",
                             InterfaceValueTools::InterfaceAverageOptions(),
                             "Type of scalar output");
  params.addClassDescription(
      "Special subclass of interface userobject giving access to interface value utilities.");
  return params;
}

InterfaceValueUserObject::InterfaceValueUserObject(const InputParameters & parameters)
  : InterfaceUserObject(parameters),
    _interface_value_type(parameters.get<MooseEnum>("interface_value_type"))
{
}

Real
InterfaceValueUserObject::computeInterfaceValueType(const Real value_master, const Real value_slave)
{
  return InterfaceValueTools::getQuantity(_interface_value_type, value_master, value_slave);
}
