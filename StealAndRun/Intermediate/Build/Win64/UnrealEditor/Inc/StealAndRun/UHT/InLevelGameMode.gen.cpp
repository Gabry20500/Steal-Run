// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "StealAndRun/Public/InLevelGameMode.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeInLevelGameMode() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	STEALANDRUN_API UClass* Z_Construct_UClass_AInLevelGameMode();
	STEALANDRUN_API UClass* Z_Construct_UClass_AInLevelGameMode_NoRegister();
	UPackage* Z_Construct_UPackage__Script_StealAndRun();
// End Cross Module References
	void AInLevelGameMode::StaticRegisterNativesAInLevelGameMode()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AInLevelGameMode);
	UClass* Z_Construct_UClass_AInLevelGameMode_NoRegister()
	{
		return AInLevelGameMode::StaticClass();
	}
	struct Z_Construct_UClass_AInLevelGameMode_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AInLevelGameMode_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_StealAndRun,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AInLevelGameMode_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AInLevelGameMode_Statics::Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "InLevelGameMode.h" },
		{ "ModuleRelativePath", "Public/InLevelGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AInLevelGameMode_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AInLevelGameMode>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AInLevelGameMode_Statics::ClassParams = {
		&AInLevelGameMode::StaticClass,
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
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AInLevelGameMode_Statics::Class_MetaDataParams), Z_Construct_UClass_AInLevelGameMode_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_AInLevelGameMode()
	{
		if (!Z_Registration_Info_UClass_AInLevelGameMode.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AInLevelGameMode.OuterSingleton, Z_Construct_UClass_AInLevelGameMode_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_AInLevelGameMode.OuterSingleton;
	}
	template<> STEALANDRUN_API UClass* StaticClass<AInLevelGameMode>()
	{
		return AInLevelGameMode::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(AInLevelGameMode);
	AInLevelGameMode::~AInLevelGameMode() {}
	struct Z_CompiledInDeferFile_FID_StealAndRun_Source_StealAndRun_Public_InLevelGameMode_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_StealAndRun_Source_StealAndRun_Public_InLevelGameMode_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AInLevelGameMode, AInLevelGameMode::StaticClass, TEXT("AInLevelGameMode"), &Z_Registration_Info_UClass_AInLevelGameMode, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AInLevelGameMode), 1149119974U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_StealAndRun_Source_StealAndRun_Public_InLevelGameMode_h_3042657082(TEXT("/Script/StealAndRun"),
		Z_CompiledInDeferFile_FID_StealAndRun_Source_StealAndRun_Public_InLevelGameMode_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_StealAndRun_Source_StealAndRun_Public_InLevelGameMode_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
