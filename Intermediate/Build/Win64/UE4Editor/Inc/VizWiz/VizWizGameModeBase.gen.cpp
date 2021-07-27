// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "VizWiz/VizWizGameModeBase.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeVizWizGameModeBase() {}
// Cross Module References
	VIZWIZ_API UClass* Z_Construct_UClass_AVizWizGameModeBase_NoRegister();
	VIZWIZ_API UClass* Z_Construct_UClass_AVizWizGameModeBase();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UPackage* Z_Construct_UPackage__Script_VizWiz();
// End Cross Module References
	void AVizWizGameModeBase::StaticRegisterNativesAVizWizGameModeBase()
	{
	}
	UClass* Z_Construct_UClass_AVizWizGameModeBase_NoRegister()
	{
		return AVizWizGameModeBase::StaticClass();
	}
	struct Z_Construct_UClass_AVizWizGameModeBase_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AVizWizGameModeBase_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_VizWiz,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVizWizGameModeBase_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "VizWizGameModeBase.h" },
		{ "ModuleRelativePath", "VizWizGameModeBase.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AVizWizGameModeBase_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AVizWizGameModeBase>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AVizWizGameModeBase_Statics::ClassParams = {
		&AVizWizGameModeBase::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x009002ACu,
		METADATA_PARAMS(Z_Construct_UClass_AVizWizGameModeBase_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AVizWizGameModeBase_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AVizWizGameModeBase()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AVizWizGameModeBase_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AVizWizGameModeBase, 1932671325);
	template<> VIZWIZ_API UClass* StaticClass<AVizWizGameModeBase>()
	{
		return AVizWizGameModeBase::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AVizWizGameModeBase(Z_Construct_UClass_AVizWizGameModeBase, &AVizWizGameModeBase::StaticClass, TEXT("/Script/VizWiz"), TEXT("AVizWizGameModeBase"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AVizWizGameModeBase);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
