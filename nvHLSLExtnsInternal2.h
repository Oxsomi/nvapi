R"(//----------------------------------------------------------------------------//

// DXR RayQuery functions

#if __SHADER_TARGET_MAJOR > 6 || (__SHADER_TARGET_MAJOR == 6 && __SHADER_TARGET_MINOR >= 5)

uint __NvRtGetCandidateClusterID(uint rqFlags)
{
    uint index = g_NvidiaExt.IncrementCounter();
    g_NvidiaExt[index].opcode = NV_EXTN_OP_RT_GET_CANDIDATE_CLUSTER_ID;
    g_NvidiaExt[index].src0u.x = rqFlags;
    return g_NvidiaExt.IncrementCounter();
}

uint __NvRtGetCommittedClusterID(uint rqFlags)
{
    uint index = g_NvidiaExt.IncrementCounter();
    g_NvidiaExt[index].opcode = NV_EXTN_OP_RT_GET_COMMITTED_CLUSTER_ID;
    g_NvidiaExt[index].src0u.x = rqFlags;
    return g_NvidiaExt.IncrementCounter();
}

float3x3 __NvRtCandidateTriangleObjectPositions(uint rqFlags)
{
    uint index = g_NvidiaExt.IncrementCounter();
    g_NvidiaExt[index].opcode = NV_EXTN_OP_RT_CANDIDATE_TRIANGLE_OBJECT_POSITIONS;
    g_NvidiaExt[index].src0u.x = rqFlags;

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

float3x3 __NvRtCommittedTriangleObjectPositions(uint rqFlags)
{
    uint index = g_NvidiaExt.IncrementCounter();
    g_NvidiaExt[index].opcode = NV_EXTN_OP_RT_COMMITTED_TRIANGLE_OBJECT_POSITIONS;
    g_NvidiaExt[index].src0u.x = rqFlags;

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

bool __NvRtCandidateIsNonOpaqueSphere(uint rqFlags)
{
    uint index = g_NvidiaExt.IncrementCounter();
    g_NvidiaExt[index].opcode = NV_EXTN_OP_RT_CANDIDATE_IS_NONOPAQUE_SPHERE;
    g_NvidiaExt[index].src0u.x = rqFlags;
    uint ret = g_NvidiaExt.IncrementCounter();
    return ret != 0;
}

bool __NvRtCandidateIsNonOpaqueLss(uint rqFlags)
{
    uint index = g_NvidiaExt.IncrementCounter();
    g_NvidiaExt[index].opcode = NV_EXTN_OP_RT_CANDIDATE_IS_NONOPAQUE_LSS;
    g_NvidiaExt[index].src0u.x = rqFlags;
    uint ret = g_NvidiaExt.IncrementCounter();
    return ret != 0;
}

float __NvRtCandidateLssHitParameter(uint rqFlags)
{
    uint index = g_NvidiaExt.IncrementCounter();
    g_NvidiaExt[index].opcode = NV_EXTN_OP_RT_CANDIDATE_LSS_HIT_PARAMETER;
    g_NvidiaExt[index].src0u.x = rqFlags;
    float ret = asfloat(g_NvidiaExt.IncrementCounter());
    return ret;
}

float4 __NvRtCandidateSphereObjectPositionAndRadius(uint rqFlags)
{
    uint index = g_NvidiaExt.IncrementCounter();
    g_NvidiaExt[index].opcode = NV_EXTN_OP_RT_CANDIDATE_SPHERE_OBJECT_POSITION_AND_RADIUS;
    g_NvidiaExt[index].src0u.x = rqFlags;

    float4 ret;
    ret[0] = asfloat(g_NvidiaExt.IncrementCounter());
    ret[1] = asfloat(g_NvidiaExt.IncrementCounter());
    ret[2] = asfloat(g_NvidiaExt.IncrementCounter());
    ret[3] = asfloat(g_NvidiaExt.IncrementCounter());
    return ret;
}

float2x4 __NvRtCandidateLssObjectPositionsAndRadii(uint rqFlags)
{
    uint index = g_NvidiaExt.IncrementCounter();
    g_NvidiaExt[index].opcode = NV_EXTN_OP_RT_CANDIDATE_LSS_OBJECT_POSITIONS_AND_RADII;
    g_NvidiaExt[index].src0u.x = rqFlags;

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

float __NvRtCandidateBuiltinPrimitiveRayT(uint rqFlags)
{
    uint index = g_NvidiaExt.IncrementCounter();
    g_NvidiaExt[index].opcode = NV_EXTN_OP_RT_CANDIDATE_BUILTIN_PRIMITIVE_RAY_T;
    g_NvidiaExt[index].src0u.x = rqFlags;
    float ret = asfloat(g_NvidiaExt.IncrementCounter());
    return ret;
}

bool __NvRtCommittedIsSphere(uint rqFlags)
{
    uint index = g_NvidiaExt.IncrementCounter();
    g_NvidiaExt[index].opcode = NV_EXTN_OP_RT_COMMITTED_IS_SPHERE;
    g_NvidiaExt[index].src0u.x = rqFlags;
    uint ret = g_NvidiaExt.IncrementCounter();
    return ret != 0;
}

bool __NvRtCommittedIsLss(uint rqFlags)
{
    uint index = g_NvidiaExt.IncrementCounter();
    g_NvidiaExt[index].opcode = NV_EXTN_OP_RT_COMMITTED_IS_LSS;
    g_NvidiaExt[index].src0u.x = rqFlags;
    uint ret = g_NvidiaExt.IncrementCounter();
    return ret != 0;
}

float __NvRtCommittedLssHitParameter(uint rqFlags)
{
    uint index = g_NvidiaExt.IncrementCounter();
    g_NvidiaExt[index].opcode = NV_EXTN_OP_RT_COMMITTED_LSS_HIT_PARAMETER;
    g_NvidiaExt[index].src0u.x = rqFlags;
    float ret = asfloat(g_NvidiaExt.IncrementCounter());
    return ret;
}

float4 __NvRtCommittedSphereObjectPositionAndRadius(uint rqFlags)
{
    uint index = g_NvidiaExt.IncrementCounter();
    g_NvidiaExt[index].opcode = NV_EXTN_OP_RT_COMMITTED_SPHERE_OBJECT_POSITION_AND_RADIUS;
    g_NvidiaExt[index].src0u.x = rqFlags;

    float4 ret;
    ret[0] = asfloat(g_NvidiaExt.IncrementCounter());
    ret[1] = asfloat(g_NvidiaExt.IncrementCounter());
    ret[2] = asfloat(g_NvidiaExt.IncrementCounter());
    ret[3] = asfloat(g_NvidiaExt.IncrementCounter());
    return ret;
}

float2x4 __NvRtCommittedLssObjectPositionsAndRadii(uint rqFlags)
{
    uint index = g_NvidiaExt.IncrementCounter();
    g_NvidiaExt[index].opcode = NV_EXTN_OP_RT_COMMITTED_LSS_OBJECT_POSITIONS_AND_RADII;
    g_NvidiaExt[index].src0u.x = rqFlags;

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

void __NvRtCommitNonOpaqueBuiltinPrimitiveHit(uint rqFlags)
{
    uint index = g_NvidiaExt.IncrementCounter();
    g_NvidiaExt[index].opcode = NV_EXTN_OP_RT_COMMIT_NONOPAQUE_BUILTIN_PRIMITIVE_HIT;
    g_NvidiaExt[index].src0u.x = rqFlags;
    uint handle = g_NvidiaExt.IncrementCounter();
}

#endif
)"
