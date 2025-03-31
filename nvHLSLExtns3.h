
R"(//----------------------------------------------------------------------------//
//------------------------- DXR HitObject Extension --------------------------//
//----------------------------------------------------------------------------//

struct NvHitObject {
    uint _handle;

    bool IsMiss()
    {
        uint index = g_NvidiaExt.IncrementCounter();
        g_NvidiaExt[index].opcode = NV_EXTN_OP_HIT_OBJECT_IS_MISS;
        g_NvidiaExt[index].src0u.x = _handle;
        uint ret = g_NvidiaExt.IncrementCounter();
        return ret != 0;
    }

    bool IsHit()
    {
        uint index = g_NvidiaExt.IncrementCounter();
        g_NvidiaExt[index].opcode = NV_EXTN_OP_HIT_OBJECT_IS_HIT;
        g_NvidiaExt[index].src0u.x = _handle;
        uint ret = g_NvidiaExt.IncrementCounter();
        return ret != 0;
    }

    bool IsNop()
    {
        uint index = g_NvidiaExt.IncrementCounter();
        g_NvidiaExt[index].opcode = NV_EXTN_OP_HIT_OBJECT_IS_NOP;
        g_NvidiaExt[index].src0u.x = _handle;
        uint ret = g_NvidiaExt.IncrementCounter();
        return ret != 0;
    }

    uint GetInstanceID()
    {
        uint index = g_NvidiaExt.IncrementCounter();
        g_NvidiaExt[index].opcode = NV_EXTN_OP_HIT_OBJECT_GET_INSTANCE_ID;
        g_NvidiaExt[index].src0u.x = _handle;
        return g_NvidiaExt.IncrementCounter();
    }

    uint GetInstanceIndex()
    {
        uint index = g_NvidiaExt.IncrementCounter();
        g_NvidiaExt[index].opcode = NV_EXTN_OP_HIT_OBJECT_GET_INSTANCE_INDEX;
        g_NvidiaExt[index].src0u.x = _handle;
        return g_NvidiaExt.IncrementCounter();
    }

    uint GetPrimitiveIndex()
    {
        uint index = g_NvidiaExt.IncrementCounter();
        g_NvidiaExt[index].opcode = NV_EXTN_OP_HIT_OBJECT_GET_PRIMITIVE_INDEX;
        g_NvidiaExt[index].src0u.x = _handle;
        return g_NvidiaExt.IncrementCounter();
    }

    uint GetGeometryIndex()
    {
        uint index = g_NvidiaExt.IncrementCounter();
        g_NvidiaExt[index].opcode = NV_EXTN_OP_HIT_OBJECT_GET_GEOMETRY_INDEX;
        g_NvidiaExt[index].src0u.x = _handle;
        return g_NvidiaExt.IncrementCounter();
    }

    uint GetHitKind()
    {
        uint index = g_NvidiaExt.IncrementCounter();
        g_NvidiaExt[index].opcode = NV_EXTN_OP_HIT_OBJECT_GET_HIT_KIND;
        g_NvidiaExt[index].src0u.x = _handle;
        return g_NvidiaExt.IncrementCounter();
    }

    RayDesc GetRayDesc()
    {
        uint index = g_NvidiaExt.IncrementCounter();
        g_NvidiaExt[index].opcode = NV_EXTN_OP_HIT_OBJECT_GET_RAY_DESC;
        g_NvidiaExt[index].src0u.x = _handle;

        uint tmin = g_NvidiaExt.IncrementCounter();
        uint tmax = g_NvidiaExt.IncrementCounter();
        uint rayOrgX = g_NvidiaExt.IncrementCounter();
        uint rayOrgY = g_NvidiaExt.IncrementCounter();
        uint rayOrgZ = g_NvidiaExt.IncrementCounter();
        uint rayDirX = g_NvidiaExt.IncrementCounter();
        uint rayDirY = g_NvidiaExt.IncrementCounter();
        uint rayDirZ = g_NvidiaExt.IncrementCounter();

        RayDesc ray;
        ray.TMin = asfloat(tmin);
        ray.TMax = asfloat(tmax);
        ray.Origin.x = asfloat(rayOrgX);
        ray.Origin.y = asfloat(rayOrgY);
        ray.Origin.z = asfloat(rayOrgZ);
        ray.Direction.x = asfloat(rayDirX);
        ray.Direction.y = asfloat(rayDirY);
        ray.Direction.z = asfloat(rayDirZ);

        return ray;
    }

    template <typename T>
    T GetAttributes()
    {
        uint index = g_NvidiaExt.IncrementCounter();
        g_NvidiaExt[index].opcode = NV_EXTN_OP_HIT_OBJECT_GET_ATTRIBUTES;
        g_NvidiaExt[index].src0u.x = _handle;
        uint callHandle = g_NvidiaExt.IncrementCounter();

        T attrs;
        CallShader(callHandle, attrs);
        return attrs;
    }

    uint GetShaderTableIndex()
    {
        uint index = g_NvidiaExt.IncrementCounter();
        g_NvidiaExt[index].opcode = NV_EXTN_OP_HIT_OBJECT_GET_SHADER_TABLE_INDEX;
        g_NvidiaExt[index].src0u.x = _handle;
        return g_NvidiaExt.IncrementCounter();
    }

    uint LoadLocalRootTableConstant(uint RootConstantOffsetInBytes)
    {
        uint index = g_NvidiaExt.IncrementCounter();
        g_NvidiaExt[index].opcode = NV_EXTN_OP_HIT_OBJECT_LOAD_LOCAL_ROOT_TABLE_CONSTANT;
        g_NvidiaExt[index].src0u.x = _handle;
        g_NvidiaExt[index].src0u.y = RootConstantOffsetInBytes;
        return g_NvidiaExt.IncrementCounter();
    }

    float4 GetSphereObjectPositionAndRadius()
    {
        uint index = g_NvidiaExt.IncrementCounter();
        g_NvidiaExt[index].opcode = NV_EXTN_OP_HIT_OBJECT_GET_SPHERE_OBJECT_POSITION_AND_RADIUS;
        g_NvidiaExt[index].src0u.x = _handle;

        float4 ret;
        ret[0] = asfloat(g_NvidiaExt.IncrementCounter());
        ret[1] = asfloat(g_NvidiaExt.IncrementCounter());
        ret[2] = asfloat(g_NvidiaExt.IncrementCounter());
        ret[3] = asfloat(g_NvidiaExt.IncrementCounter());
        return ret;
    }

    float2x4 GetLssObjectPositionsAndRadii()
    {
        uint index = g_NvidiaExt.IncrementCounter();
        g_NvidiaExt[index].opcode = NV_EXTN_OP_HIT_OBJECT_GET_LSS_OBJECT_POSITIONS_AND_RADII;
        g_NvidiaExt[index].src0u.x = _handle;

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

    bool IsSphereHit()
    {
        uint index = g_NvidiaExt.IncrementCounter();
        g_NvidiaExt[index].opcode = NV_EXTN_OP_HIT_OBJECT_IS_SPHERE_HIT;
        g_NvidiaExt[index].src0u.x = _handle;
        uint ret = g_NvidiaExt.IncrementCounter();
        return ret != 0;
    }

    bool IsLssHit()
    {
        uint index = g_NvidiaExt.IncrementCounter();
        g_NvidiaExt[index].opcode = NV_EXTN_OP_HIT_OBJECT_IS_LSS_HIT;
        g_NvidiaExt[index].src0u.x = _handle;
        uint ret = g_NvidiaExt.IncrementCounter();
        return ret != 0;
    }

    uint GetClusterID()
    {
        uint index = g_NvidiaExt.IncrementCounter();
        g_NvidiaExt[index].opcode = NV_EXTN_OP_HIT_OBJECT_GET_CLUSTER_ID;
        g_NvidiaExt[index].src0u.x = _handle;
        return g_NvidiaExt.IncrementCounter();
    }

    float3x3 GetTriangleObjectPositions()
    {
        uint index = g_NvidiaExt.IncrementCounter();
        g_NvidiaExt[index].opcode = NV_EXTN_OP_HIT_OBJECT_GET_TRIANGLE_OBJECT_POSITIONS;
        g_NvidiaExt[index].src0u.x = _handle;

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
};

template<typename T>
NvHitObject NvTraceRayHitObject(
    RaytracingAccelerationStructure AccelerationStructure,
    uint RayFlags,
    uint InstanceInclusionMask,
    uint RayContributionToHitGroupIndex,
    uint MultiplierForGeometryContributionToHitGroupIndex,
    uint MissShaderIndex,
    RayDesc Ray,
    inout T Payload)
{
    uint index = g_NvidiaExt.IncrementCounter();
    g_NvidiaExt[index].opcode = NV_EXTN_OP_HIT_OBJECT_TRACE_RAY;
    g_NvidiaExt[index].numOutputsForIncCounter = 2;
    g_NvidiaExt[index].src0u.x = MissShaderIndex;
    uint hitHandle = g_NvidiaExt.IncrementCounter();
    uint traceHandle = g_NvidiaExt.IncrementCounter();

    TraceRay(AccelerationStructure, RayFlags, InstanceInclusionMask, RayContributionToHitGroupIndex, MultiplierForGeometryContributionToHitGroupIndex, traceHandle, Ray, Payload);

    NvHitObject hitObj;
    hitObj._handle = hitHandle;
    return hitObj;
}

template <typename T>
NvHitObject NvMakeHit(
    RaytracingAccelerationStructure AccelerationStructure,
    uint InstanceIndex,
    uint GeometryIndex,
    uint PrimitiveIndex,
    uint HitKind,
    uint RayContributionToHitGroupIndex,
    uint MultiplierForGeometryContributionToHitGroupIndex,
    RayDesc Ray,
    T Attributes)
{
    uint index = g_NvidiaExt.IncrementCounter();
    g_NvidiaExt[index].opcode = NV_EXTN_OP_HIT_OBJECT_MAKE_HIT;
    g_NvidiaExt[index].numOutputsForIncCounter = 2;
    g_NvidiaExt[index].src0u.x = InstanceIndex;
    g_NvidiaExt[index].src0u.y = GeometryIndex;
    g_NvidiaExt[index].src0u.z = PrimitiveIndex;
    g_NvidiaExt[index].src0u.w = HitKind;
    g_NvidiaExt[index].src1u.x = RayContributionToHitGroupIndex;
    g_NvidiaExt[index].src1u.y = MultiplierForGeometryContributionToHitGroupIndex;
    uint hitHandle = g_NvidiaExt.IncrementCounter();
    uint traceHandle = g_NvidiaExt.IncrementCounter();

    struct AttrWrapper { T Attrs; };
    AttrWrapper wrapper;
    wrapper.Attrs = Attributes;
    CallShader(traceHandle, wrapper);

    struct DummyPayload { int a; };
    DummyPayload payload;
    TraceRay(AccelerationStructure, 0, 0, 0, 0, traceHandle, Ray, payload);

    NvHitObject hitObj;
    hitObj._handle = hitHandle;
    return hitObj;
}

template <typename T>
NvHitObject NvMakeHitWithRecordIndex(
    uint HitGroupRecordIndex,
    RaytracingAccelerationStructure AccelerationStructure,
    uint InstanceIndex,
    uint GeometryIndex,
    uint PrimitiveIndex,
    uint HitKind,
    RayDesc Ray,
    T Attributes)
{
    uint index = g_NvidiaExt.IncrementCounter();
    g_NvidiaExt[index].opcode = NV_EXTN_OP_HIT_OBJECT_MAKE_HIT_WITH_RECORD_INDEX;
    g_NvidiaExt[index].numOutputsForIncCounter = 2;
    g_NvidiaExt[index].src0u.x = InstanceIndex;
    g_NvidiaExt[index].src0u.y = GeometryIndex;
    g_NvidiaExt[index].src0u.z = PrimitiveIndex;
    g_NvidiaExt[index].src0u.w = HitKind;
    g_NvidiaExt[index].src1u.x = HitGroupRecordIndex;
    uint hitHandle = g_NvidiaExt.IncrementCounter();
    uint traceHandle = g_NvidiaExt.IncrementCounter();

    struct AttrWrapper { T Attrs; };
    AttrWrapper wrapper;
    wrapper.Attrs = Attributes;
    CallShader(traceHandle, wrapper);

    struct DummyPayload { int a; };
    DummyPayload payload;
    TraceRay(AccelerationStructure, 0, 0, 0, 0, traceHandle, Ray, payload);

    NvHitObject hitObj;
    hitObj._handle = hitHandle;
    return hitObj;
}

NvHitObject NvMakeMiss(
    uint MissShaderIndex,
    RayDesc Ray)
{
    uint index = g_NvidiaExt.IncrementCounter();
    g_NvidiaExt[index].opcode = NV_EXTN_OP_HIT_OBJECT_MAKE_MISS;
    g_NvidiaExt[index].src0u.x = MissShaderIndex;
    g_NvidiaExt[index].src0u.y = asuint(Ray.TMin);
    g_NvidiaExt[index].src0u.z = asuint(Ray.TMax);
    g_NvidiaExt[index].src1u.x = asuint(Ray.Origin.x);
    g_NvidiaExt[index].src1u.y = asuint(Ray.Origin.y);
    g_NvidiaExt[index].src1u.z = asuint(Ray.Origin.z);
    g_NvidiaExt[index].src2u.x = asuint(Ray.Direction.x);
    g_NvidiaExt[index].src2u.y = asuint(Ray.Direction.y);
    g_NvidiaExt[index].src2u.z = asuint(Ray.Direction.z);
    uint hitHandle = g_NvidiaExt.IncrementCounter();

    NvHitObject hitObj;
    hitObj._handle = hitHandle;
    return hitObj;
}

NvHitObject NvMakeNop()
{
    uint index = g_NvidiaExt.IncrementCounter();
    g_NvidiaExt[index].opcode = NV_EXTN_OP_HIT_OBJECT_MAKE_NOP;
    uint hitHandle = g_NvidiaExt.IncrementCounter();

    NvHitObject hitObj;
    hitObj._handle = hitHandle;
    return hitObj;
}

void NvReorderThread(uint CoherenceHint, uint NumCoherenceHintBits)
{
    uint index = g_NvidiaExt.IncrementCounter();
    g_NvidiaExt[index].opcode = NV_EXTN_OP_HIT_OBJECT_REORDER_THREAD;
    g_NvidiaExt[index].src0u.x = 0;
    g_NvidiaExt[index].src0u.y = 0;
    g_NvidiaExt[index].src0u.z = CoherenceHint;
    g_NvidiaExt[index].src0u.w = NumCoherenceHintBits;
    g_NvidiaExt.IncrementCounter();
}

void NvReorderThread(NvHitObject HitObj, uint CoherenceHint, uint NumCoherenceHintBits)
{
    uint index = g_NvidiaExt.IncrementCounter();
    g_NvidiaExt[index].opcode = NV_EXTN_OP_HIT_OBJECT_REORDER_THREAD;
    g_NvidiaExt[index].src0u.x = 1;
    g_NvidiaExt[index].src0u.y = HitObj._handle;
    g_NvidiaExt[index].src0u.z = CoherenceHint;
    g_NvidiaExt[index].src0u.w = NumCoherenceHintBits;
    g_NvidiaExt.IncrementCounter();
}

void NvReorderThread(NvHitObject HitObj)
{
    NvReorderThread(HitObj, 0, 0);
}

template<typename T>
void NvInvokeHitObject(
    RaytracingAccelerationStructure AccelerationStructure,
    NvHitObject HitObj,
    inout T Payload)
{
    uint index = g_NvidiaExt.IncrementCounter();
    g_NvidiaExt[index].opcode = NV_EXTN_OP_HIT_OBJECT_INVOKE;
    g_NvidiaExt[index].src0u.x = HitObj._handle;
    uint handle = g_NvidiaExt.IncrementCounter();

    TraceRay(AccelerationStructure, 0, 0, 0, 0, handle, (RayDesc)0, Payload);
}

)"