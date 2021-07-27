// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "VizWiz/SpectralVisualizer.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSpectralVisualizer() {}
// Cross Module References
	VIZWIZ_API UClass* Z_Construct_UClass_ASpectralVisualizer_NoRegister();
	VIZWIZ_API UClass* Z_Construct_UClass_ASpectralVisualizer();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_VizWiz();
// End Cross Module References
	void ASpectralVisualizer::StaticRegisterNativesASpectralVisualizer()
	{
	}
	UClass* Z_Construct_UClass_ASpectralVisualizer_NoRegister()
	{
		return ASpectralVisualizer::StaticClass();
	}
	struct Z_Construct_UClass_ASpectralVisualizer_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ASpectralVisualizer_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_VizWiz,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASpectralVisualizer_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "SpectralVisualizer.h" },
		{ "ModuleRelativePath", "SpectralVisualizer.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ASpectralVisualizer_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ASpectralVisualizer>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ASpectralVisualizer_Statics::ClassParams = {
		&ASpectralVisualizer::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_ASpectralVisualizer_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ASpectralVisualizer_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ASpectralVisualizer()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ASpectralVisualizer_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ASpectralVisualizer, 2959488670);
	template<> VIZWIZ_API UClass* StaticClass<ASpectralVisualizer>()
	{
		return ASpectralVisualizer::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ASpectralVisualizer(Z_Construct_UClass_ASpectralVisualizer, &ASpectralVisualizer::StaticClass, TEXT("/Script/VizWiz"), TEXT("ASpectralVisualizer"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ASpectralVisualizer);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
