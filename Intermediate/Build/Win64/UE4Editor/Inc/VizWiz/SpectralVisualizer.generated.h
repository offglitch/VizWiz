// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef VIZWIZ_SpectralVisualizer_generated_h
#error "SpectralVisualizer.generated.h already included, missing '#pragma once' in SpectralVisualizer.h"
#endif
#define VIZWIZ_SpectralVisualizer_generated_h

#define VizWiz_Source_VizWiz_SpectralVisualizer_h_12_SPARSE_DATA
#define VizWiz_Source_VizWiz_SpectralVisualizer_h_12_RPC_WRAPPERS
#define VizWiz_Source_VizWiz_SpectralVisualizer_h_12_RPC_WRAPPERS_NO_PURE_DECLS
#define VizWiz_Source_VizWiz_SpectralVisualizer_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesASpectralVisualizer(); \
	friend struct Z_Construct_UClass_ASpectralVisualizer_Statics; \
public: \
	DECLARE_CLASS(ASpectralVisualizer, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/VizWiz"), NO_API) \
	DECLARE_SERIALIZER(ASpectralVisualizer)


#define VizWiz_Source_VizWiz_SpectralVisualizer_h_12_INCLASS \
private: \
	static void StaticRegisterNativesASpectralVisualizer(); \
	friend struct Z_Construct_UClass_ASpectralVisualizer_Statics; \
public: \
	DECLARE_CLASS(ASpectralVisualizer, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/VizWiz"), NO_API) \
	DECLARE_SERIALIZER(ASpectralVisualizer)


#define VizWiz_Source_VizWiz_SpectralVisualizer_h_12_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ASpectralVisualizer(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ASpectralVisualizer) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ASpectralVisualizer); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ASpectralVisualizer); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ASpectralVisualizer(ASpectralVisualizer&&); \
	NO_API ASpectralVisualizer(const ASpectralVisualizer&); \
public:


#define VizWiz_Source_VizWiz_SpectralVisualizer_h_12_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ASpectralVisualizer(ASpectralVisualizer&&); \
	NO_API ASpectralVisualizer(const ASpectralVisualizer&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ASpectralVisualizer); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ASpectralVisualizer); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ASpectralVisualizer)


#define VizWiz_Source_VizWiz_SpectralVisualizer_h_12_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__TimeSynthComponent() { return STRUCT_OFFSET(ASpectralVisualizer, TimeSynthComponent); } \
	FORCEINLINE static uint32 __PPO__TimeSynthClip() { return STRUCT_OFFSET(ASpectralVisualizer, TimeSynthClip); } \
	FORCEINLINE static uint32 __PPO__SpectrumBars() { return STRUCT_OFFSET(ASpectralVisualizer, SpectrumBars); } \
	FORCEINLINE static uint32 __PPO__SpectrumBarSpacing() { return STRUCT_OFFSET(ASpectralVisualizer, SpectrumBarSpacing); }


#define VizWiz_Source_VizWiz_SpectralVisualizer_h_9_PROLOG
#define VizWiz_Source_VizWiz_SpectralVisualizer_h_12_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	VizWiz_Source_VizWiz_SpectralVisualizer_h_12_PRIVATE_PROPERTY_OFFSET \
	VizWiz_Source_VizWiz_SpectralVisualizer_h_12_SPARSE_DATA \
	VizWiz_Source_VizWiz_SpectralVisualizer_h_12_RPC_WRAPPERS \
	VizWiz_Source_VizWiz_SpectralVisualizer_h_12_INCLASS \
	VizWiz_Source_VizWiz_SpectralVisualizer_h_12_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define VizWiz_Source_VizWiz_SpectralVisualizer_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	VizWiz_Source_VizWiz_SpectralVisualizer_h_12_PRIVATE_PROPERTY_OFFSET \
	VizWiz_Source_VizWiz_SpectralVisualizer_h_12_SPARSE_DATA \
	VizWiz_Source_VizWiz_SpectralVisualizer_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	VizWiz_Source_VizWiz_SpectralVisualizer_h_12_INCLASS_NO_PURE_DECLS \
	VizWiz_Source_VizWiz_SpectralVisualizer_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> VIZWIZ_API UClass* StaticClass<class ASpectralVisualizer>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID VizWiz_Source_VizWiz_SpectralVisualizer_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
