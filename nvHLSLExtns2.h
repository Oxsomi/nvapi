R"({
    uint index = g_NvidiaExt.IncrementCounter();
    g_NvidiaExt[index].opcode = NV_EXTN_OP_RT_TRIANGLE_OBJECT_POSITIONS;

    float3x3 ret;
    ret[0][0] = asfloat(g_NvidiaExt.IncrementCounter());
    ret[0][1] = asfloat(g_NvidiaExt.IncrementCounter());
    ret[0][2] = asfloat(g_NvidiaExt.IncrementCounter());
    ret[1][0] = asfloat(g_NvidiaExt.IncrementCounter());
    ret[1][1] = asfloat(g_NvidiaExt.IncrementCounter());
    ret[1][2] = asfloat(g_NvidiaExt.IncrementCounter());
    ret[2][0] = asfloat(g_NvidiaExt.IncrementCounter());
    ret[2][1] = asfloat(g_NvidiaExt.IncrementCounter());
    ret[2][2] = asfloat(g_NvidiaExt.IncrementCounter());
    return ret;
}

float3x3 NvRtMicroTriangleObjectPositions()
{
    uint index = g_NvidiaExt.IncrementCounter();
    g_NvidiaExt[index].opcode = NV_EXTN_OP_RT_MICRO_TRIANGLE_OBJECT_POSITIONS;

    float3x3 ret;
    ret[0][0] = asfloat(g_NvidiaExt.IncrementCounter());
    ret[0][1] = asfloat(g_NvidiaExt.IncrementCounter());
    ret[0][2] = asfloat(g_NvidiaExt.IncrementCounter());
    ret[1][0] = asfloat(g_NvidiaExt.IncrementCounter());
    ret[1][1] = asfloat(g_NvidiaExt.IncrementCounter());
    ret[1][2] = asfloat(g_NvidiaExt.IncrementCounter());
    ret[2][0] = asfloat(g_NvidiaExt.IncrementCounter());
    ret[2][1] = asfloat(g_NvidiaExt.IncrementCounter());
    ret[2][2] = asfloat(g_NvidiaExt.IncrementCounter());
    return ret;
}

float3x2 NvRtMicroTriangleBarycentrics()
{
    uint index = g_NvidiaExt.IncrementCounter();
    g_NvidiaExt[index].opcode = NV_EXTN_OP_RT_MICRO_TRIANGLE_BARYCENTRICS;

    float3x2 ret;
    ret[0][0] = asfloat(g_NvidiaExt.IncrementCounter());
    ret[0][1] = asfloat(g_NvidiaExt.IncrementCounter());
    ret[1][0] = asfloat(g_NvidiaExt.IncrementCounter());
    ret[1][1] = asfloat(g_NvidiaExt.IncrementCounter());
    ret[2][0] = asfloat(g_NvidiaExt.IncrementCounter());
    ret[2][1] = asfloat(g_NvidiaExt.IncrementCounter());
    return ret;
}

bool NvRtIsMicroTriangleHit()
{
    uint index = g_NvidiaExt.IncrementCounter();
    g_NvidiaExt[index].opcode = NV_EXTN_OP_RT_IS_MICRO_TRIANGLE_HIT;
    uint ret = g_NvidiaExt.IncrementCounter();
    return ret != 0;
}

bool NvRtIsBackFacing()
{
    uint index = g_NvidiaExt.IncrementCounter();
    g_NvidiaExt[index].opcode = NV_EXTN_OP_RT_IS_BACK_FACING;
    uint ret = g_NvidiaExt.IncrementCounter();
    return ret != 0;
}

#if __SHADER_TARGET_MAJOR > 6 || (__SHADER_TARGET_MAJOR == 6 && __SHADER_TARGET_MINOR >= 5)

float3 NvRtMicroVertexObjectPosition(RaytracingAccelerationStructure AccelerationStructure, uint InstanceIndex, uint GeometryIndex, uint PrimitiveIndex, uint2 UV)
{
    uint index = g_NvidiaExt.IncrementCounter();
    g_NvidiaExt[index].opcode = NV_EXTN_OP_RT_MICRO_VERTEX_OBJECT_POSITION;
    g_NvidiaExt[index].src0u.x = InstanceIndex;
    g_NvidiaExt[index].src0u.y = GeometryIndex;
    g_NvidiaExt[index].src0u.z = PrimitiveIndex;
    g_NvidiaExt[index].src0u.w = UV.x;
    g_NvidiaExt[index].src1u.x = UV.y;
    uint handle = g_NvidiaExt.IncrementCounter();
    float3 ret;
    ret.x = asfloat(g_NvidiaExt.IncrementCounter());
    ret.y = asfloat(g_NvidiaExt.IncrementCounter());
    ret.z = asfloat(g_NvidiaExt.IncrementCounter());

    RayQuery<0> rq;
    rq.TraceRayInline(AccelerationStructure, 0, handle, (RayDesc)0);

    return ret;
}

float2 NvRtMicroVertexBarycentrics(RaytracingAccelerationStructure AccelerationStructure, uint InstanceIndex, uint GeometryIndex, uint PrimitiveIndex, uint2 UV)
{
    uint index = g_NvidiaExt.IncrementCounter();
    g_NvidiaExt[index].opcode = NV_EXTN_OP_RT_MICRO_VERTEX_BARYCENTRICS;
    g_NvidiaExt[index].src0u.x = InstanceIndex;
    g_NvidiaExt[index].src0u.y = GeometryIndex;
    g_NvidiaExt[index].src0u.z = PrimitiveIndex;
    g_NvidiaExt[index].src0u.w = UV.x;
    g_NvidiaExt[index].src1u.x = UV.y;
    uint handle = g_NvidiaExt.IncrementCounter();
    float2 ret;
    ret.x = asfloat(g_NvidiaExt.IncrementCounter());
    ret.y = asfloat(g_NvidiaExt.IncrementCounter());

    RayQuery<0> rq;
    rq.TraceRayInline(AccelerationStructure, 0, handle, (RayDesc)0);

    return ret;
}

#endif

//----------------------------------------------------------------------------//
//--------------------- DXR Cluster Geometry Extension -----------------------//
//----------------------------------------------------------------------------//

#if __SHADER_TARGET_MAJOR > 6 || (__SHADER_TARGET_MAJOR == 6 && __SHADER_TARGET_MINOR >= 3)

uint NvRtGetClusterID()
{
    uint index = g_NvidiaExt.IncrementCounter();
    g_NvidiaExt[index].opcode = NV_EXTN_OP_RT_GET_CLUSTER_ID;
    return g_NvidiaExt.IncrementCounter();
}

#endif

#if __SHADER_TARGET_MAJOR > 6 || (__SHADER_TARGET_MAJOR == 6 && __SHADER_TARGET_MINOR >= 5)

#define NvRtGetCandidateClusterID(rq) __NvRtGetCandidateClusterID(rq.RayFlags())

#define NvRtGetCommittedClusterID(rq) __NvRtGetCommittedClusterID(rq.RayFlags())

#define NvRtCandidateTriangleObjectPositions(rq) __NvRtCandidateTriangleObjectPositions(rq.RayFlags())

#define NvRtCommittedTriangleObjectPositions(rq) __NvRtCommittedTriangleObjectPositions(rq.RayFlags())

#endif

//----------------------------------------------------------------------------//
//--------------------- DXR Linear Swept Sphere Extension --------------------//
//----------------------------------------------------------------------------//

#if __SHADER_TARGET_MAJOR > 6 || (__SHADER_TARGET_MAJOR == 6 && __SHADER_TARGET_MINOR >= 3)

float4 NvRtSphereObjectPositionAndRadius()
{
    uint index = g_NvidiaExt.IncrementCounter();
    g_NvidiaExt[index].opcode = NV_EXTN_OP_RT_SPHERE_OBJECT_POSITION_AND_RADIUS;

    float4 ret;
    ret[0] = asfloat(g_NvidiaExt.IncrementCounter());
    ret[1] = asfloat(g_NvidiaExt.IncrementCounter());
    ret[2] = asfloat(g_NvidiaExt.IncrementCounter());
    ret[3] = asfloat(g_NvidiaExt.IncrementCounter());
    return ret;
}

float2x4 NvRtLssObjectPositionsAndRadii()
{
    uint index = g_NvidiaExt.IncrementCounter();
    g_NvidiaExt[index].opcode = NV_EXTN_OP_RT_LSS_OBJECT_POSITIONS_AND_RADII;

    float2x4 ret;
    ret[0][0] = asfloat(g_NvidiaExt.IncrementCounter());
    ret[0][1] = asfloat(g_NvidiaExt.IncrementCounter());
    ret[0][2] = asfloat(g_NvidiaExt.IncrementCounter());
    ret[0][3] = asfloat(g_NvidiaExt.IncrementCounter());
    ret[1][0] = asfloat(g_NvidiaExt.IncrementCounter());
    ret[1][1] = asfloat(g_NvidiaExt.IncrementCounter());
    ret[1][2] = asfloat(g_NvidiaExt.IncrementCounter());
    ret[1][3] = asfloat(g_NvidiaExt.IncrementCounter());
    return ret;
}

bool NvRtIsSphereHit()
{
    uint index = g_NvidiaExt.IncrementCounter();
    g_NvidiaExt[index].opcode = NV_EXTN_OP_RT_IS_SPHERE_HIT;
    uint ret = g_NvidiaExt.IncrementCounter();
    return ret != 0;
}

bool NvRtIsLssHit()
{
    uint index = g_NvidiaExt.IncrementCounter();
    g_NvidiaExt[index].opcode = NV_EXTN_OP_RT_IS_LSS_HIT;
    uint ret = g_NvidiaExt.IncrementCounter();
    return ret != 0;
}

#endif

#if __SHADER_TARGET_MAJOR > 6 || (__SHADER_TARGET_MAJOR == 6 && __SHADER_TARGET_MINOR >= 5)

#define NvRtCandidateIsNonOpaqueSphere(rq) __NvRtCandidateIsNonOpaqueSphere(rq.RayFlags())

#define NvRtCandidateIsNonOpaqueLss(rq) __NvRtCandidateIsNonOpaqueLss(rq.RayFlags())

#define NvRtCandidateLssHitParameter(rq) __NvRtCandidateLssHitParameter(rq.RayFlags())

#define NvRtCandidateSphereObjectPositionAndRadius(rq) __NvRtCandidateSphereObjectPositionAndRadius(rq.RayFlags())

#define NvRtCandidateLssObjectPositionsAndRadii(rq) __NvRtCandidateLssObjectPositionsAndRadii(rq.RayFlags())

#define NvRtCandidateBuiltinPrimitiveRayT(rq) __NvRtCandidateBuiltinPrimitiveRayT(rq.RayFlags())

#define NvRtCommittedIsSphere(rq) __NvRtCommittedIsSphere(rq.RayFlags())

#define NvRtCommittedIsLss(rq) __NvRtCommittedIsLss(rq.RayFlags())

#define NvRtCommittedLssHitParameter(rq) __NvRtCommittedLssHitParameter(rq.RayFlags())

#define NvRtCommittedSphereObjectPositionAndRadius(rq) __NvRtCommittedSphereObjectPositionAndRadius(rq.RayFlags())

#define NvRtCommittedLssObjectPositionsAndRadii(rq) __NvRtCommittedLssObjectPositionsAndRadii(rq.RayFlags())

#define NvRtCommitNonOpaqueBuiltinPrimitiveHit(rq) __NvRtCommitNonOpaqueBuiltinPrimitiveHit(rq.RayFlags())

#endif

)"