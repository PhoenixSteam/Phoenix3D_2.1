// PX2Box3.inl

//----------------------------------------------------------------------------
template <typename Real>
Box3<Real>::Box3 ()
{
}
//----------------------------------------------------------------------------
template <typename Real>
Box3<Real>::~Box3 ()
{
}
//----------------------------------------------------------------------------
template <typename Real>
Box3<Real>::Box3 (const Vector3<Real>& center, const Vector3<Real> axis[3],
				  const Real extent[3])
				  :
Center(center)
{
	Axis[0] = axis[0];
	Axis[1] = axis[1];
	Axis[2] = axis[2];
	Extent[0] = extent[0];
	Extent[1] = extent[1];
	Extent[2] = extent[2];
}
//----------------------------------------------------------------------------
template <typename Real>
Box3<Real>::Box3 (const Vector3<Real>& center, const Vector3<Real>& axis0,
				  const Vector3<Real>& axis1, const Vector3<Real>& axis2,
				  const Real extent0, const Real extent1, const Real extent2)
				  :
Center(center)
{
	Axis[0] = axis0;
	Axis[1] = axis1;
	Axis[2] = axis2;
	Extent[0] = extent0;
	Extent[1] = extent1;
	Extent[2] = extent2;
}
//----------------------------------------------------------------------------
template <typename Real>
void Box3<Real>::ComputeVertices (Vector3<Real> vertex[8]) const
{
	Vector3<Real> extAxis0 = Extent[0]*Axis[0];
	Vector3<Real> extAxis1 = Extent[1]*Axis[1];
	Vector3<Real> extAxis2 = Extent[2]*Axis[2];

	vertex[0] = Center - extAxis0 - extAxis1 - extAxis2;
	vertex[1] = Center + extAxis0 - extAxis1 - extAxis2;
	vertex[2] = Center + extAxis0 + extAxis1 - extAxis2;
	vertex[3] = Center - extAxis0 + extAxis1 - extAxis2;
	vertex[4] = Center - extAxis0 - extAxis1 + extAxis2;
	vertex[5] = Center + extAxis0 - extAxis1 + extAxis2;
	vertex[6] = Center + extAxis0 + extAxis1 + extAxis2;
	vertex[7] = Center - extAxis0 + extAxis1 + extAxis2;
}
//----------------------------------------------------------------------------
