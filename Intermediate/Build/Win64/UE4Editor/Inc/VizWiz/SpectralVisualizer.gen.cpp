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
	TIMESYNTH_API UClass* Z_Construct_UClass_UTimeSynthComponent_NoRegister();
	TIMESYNTH_API UClass* Z_Construct_UClass_UTimeSynthClip_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
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
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_TimeSynthComponent_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_TimeSynthComponent;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_TimeSynthClip_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_TimeSynthClip;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_SpectrumBars_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_SpectrumBars_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_SpectrumBars;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_SpectrumBarSpacing_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_SpectrumBarSpacing;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
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
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASpectralVisualizer_Statics::NewProp_TimeSynthComponent_MetaData[] = {
		{ "Category", "Audio" },
		{ "Comment", "//This is the core of the actor, the TimeSynth component\n" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "SpectralVisualizer.h" },
		{ "ToolTip", "This is the core of the actor, the TimeSynth component" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ASpectralVisualizer_Statics::NewProp_TimeSynthComponent = { "TimeSynthComponent", nullptr, (EPropertyFlags)0x0020080000080009, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ASpectralVisualizer, TimeSynthComponent), Z_Construct_UClass_UTimeSynthComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ASpectralVisualizer_Statics::NewProp_TimeSynthComponent_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASpectralVisualizer_Statics::NewProp_TimeSynthComponent_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASpectralVisualizer_Statics::NewProp_TimeSynthClip_MetaData[] = {
		{ "Category", "Audio" },
		{ "Comment", "//TSClip represents that piece of audio from TSComponent \n" },
		{ "ModuleRelativePath", "SpectralVisualizer.h" },
		{ "ToolTip", "TSClip represents that piece of audio from TSComponent" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ASpectralVisualizer_Statics::NewProp_TimeSynthClip = { "TimeSynthClip", nullptr, (EPropertyFlags)0x0020080000000001, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ASpectralVisualizer, TimeSynthClip), Z_Construct_UClass_UTimeSynthClip_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ASpectralVisualizer_Statics::NewProp_TimeSynthClip_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASpectralVisualizer_Statics::NewProp_TimeSynthClip_MetaData)) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ASpectralVisualizer_Statics::NewProp_SpectrumBars_Inner = { "SpectrumBars", nullptr, (EPropertyFlags)0x0000000000080008, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASpectralVisualizer_Statics::NewProp_SpectrumBars_MetaData[] = {
		{ "Category", "Audio" },
		{ "Comment", "//Creating an array of meshes to bounce up and down, using the static mesh component\n//These bars just represent the different frequencies in an audio file\n" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "SpectralVisualizer.h" },
		{ "ToolTip", "Creating an array of meshes to bounce up and down, using the static mesh component\nThese bars just represent the different frequencies in an audio file" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_ASpectralVisualizer_Statics::NewProp_SpectrumBars = { "SpectrumBars", nullptr, (EPropertyFlags)0x0020088000000009, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ASpectralVisualizer, SpectrumBars), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_ASpectralVisualizer_Statics::NewProp_SpectrumBars_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASpectralVisualizer_Statics::NewProp_SpectrumBars_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASpectralVisualizer_Statics::NewProp_SpectrumBarSpacing_MetaData[] = {
		{ "Category", "Audio" },
		{ "Comment", "//The spacing between each bar, allows the bars to move away from each other\n" },
		{ "ModuleRelativePath", "SpectralVisualizer.h" },
		{ "ToolTip", "The spacing between each bar, allows the bars to move away from each other" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ASpectralVisualizer_Statics::NewProp_SpectrumBarSpacing = { "SpectrumBarSpacing", nullptr, (EPropertyFlags)0x0020080000000001, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ASpectralVisualizer, SpectrumBarSpacing), METADATA_PARAMS(Z_Construct_UClass_ASpectralVisualizer_Statics::NewProp_SpectrumBarSpacing_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASpectralVisualizer_Statics::NewProp_SpectrumBarSpacing_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ASpectralVisualizer_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASpectralVisualizer_Statics::NewProp_TimeSynthComponent,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASpectralVisualizer_Statics::NewProp_TimeSynthClip,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASpectralVisualizer_Statics::NewProp_SpectrumBars_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASpectralVisualizer_Statics::NewProp_SpectrumBars,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASpectralVisualizer_Statics::NewProp_SpectrumBarSpacing,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ASpectralVisualizer_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ASpectralVisualizer>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ASpectralVisualizer_Statics::ClassParams = {
		&ASpectralVisualizer::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_ASpectralVisualizer_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_ASpectralVisualizer_Statics::PropPointers),
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
	IMPLEMENT_CLASS(ASpectralVisualizer, 537848479);
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
