// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "StealAndRun/Public/PlayerPawn.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePlayerPawn() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_APawn();
	ENGINE_API UClass* Z_Construct_UClass_UBoxComponent_NoRegister();
	STEALANDRUN_API UClass* Z_Construct_UClass_APlayerPawn();
	STEALANDRUN_API UClass* Z_Construct_UClass_APlayerPawn_NoRegister();
	UPackage* Z_Construct_UPackage__Script_StealAndRun();
// End Cross Module References
	DEFINE_FUNCTION(APlayerPawn::execOnShiftReleased)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->OnShiftReleased();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(APlayerPawn::execOnShiftPressed)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->OnShiftPressed();
		P_NATIVE_END;
	}
	void APlayerPawn::StaticRegisterNativesAPlayerPawn()
	{
		UClass* Class = APlayerPawn::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "OnShiftPressed", &APlayerPawn::execOnShiftPressed },
			{ "OnShiftReleased", &APlayerPawn::execOnShiftReleased },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_APlayerPawn_OnShiftPressed_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_APlayerPawn_OnShiftPressed_Statics::Function_MetaDataParams[] = {
		{ "Category", "PlayerPawn" },
		{ "ModuleRelativePath", "Public/PlayerPawn.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_APlayerPawn_OnShiftPressed_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_APlayerPawn, nullptr, "OnShiftPressed", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_APlayerPawn_OnShiftPressed_Statics::Function_MetaDataParams), Z_Construct_UFunction_APlayerPawn_OnShiftPressed_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_APlayerPawn_OnShiftPressed()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_APlayerPawn_OnShiftPressed_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_APlayerPawn_OnShiftReleased_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_APlayerPawn_OnShiftReleased_Statics::Function_MetaDataParams[] = {
		{ "Category", "PlayerPawn" },
		{ "ModuleRelativePath", "Public/PlayerPawn.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_APlayerPawn_OnShiftReleased_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_APlayerPawn, nullptr, "OnShiftReleased", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_APlayerPawn_OnShiftReleased_Statics::Function_MetaDataParams), Z_Construct_UFunction_APlayerPawn_OnShiftReleased_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_APlayerPawn_OnShiftReleased()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_APlayerPawn_OnShiftReleased_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(APlayerPawn);
	UClass* Z_Construct_UClass_APlayerPawn_NoRegister()
	{
		return APlayerPawn::StaticClass();
	}
	struct Z_Construct_UClass_APlayerPawn_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_PlayerCollisionComponent_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_PlayerCollisionComponent;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_BaseMoveForce_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_BaseMoveForce;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_TargetMoveForce_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_TargetMoveForce;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ShiftMultiplayer_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_ShiftMultiplayer;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_APlayerPawn_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_APawn,
		(UObject* (*)())Z_Construct_UPackage__Script_StealAndRun,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_APlayerPawn_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_APlayerPawn_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_APlayerPawn_OnShiftPressed, "OnShiftPressed" }, // 2304446615
		{ &Z_Construct_UFunction_APlayerPawn_OnShiftReleased, "OnShiftReleased" }, // 3486235248
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_APlayerPawn_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APlayerPawn_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "PlayerPawn.h" },
		{ "ModuleRelativePath", "Public/PlayerPawn.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APlayerPawn_Statics::NewProp_PlayerCollisionComponent_MetaData[] = {
		{ "Category", "PlayerPawn" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*VARIABLE*/" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/PlayerPawn.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "VARIABLE" },
#endif
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_APlayerPawn_Statics::NewProp_PlayerCollisionComponent = { "PlayerCollisionComponent", nullptr, (EPropertyFlags)0x0010000000080009, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(APlayerPawn, PlayerCollisionComponent), Z_Construct_UClass_UBoxComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_APlayerPawn_Statics::NewProp_PlayerCollisionComponent_MetaData), Z_Construct_UClass_APlayerPawn_Statics::NewProp_PlayerCollisionComponent_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APlayerPawn_Statics::NewProp_BaseMoveForce_MetaData[] = {
		{ "Category", "PlayerPawn" },
		{ "ModuleRelativePath", "Public/PlayerPawn.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_APlayerPawn_Statics::NewProp_BaseMoveForce = { "BaseMoveForce", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(APlayerPawn, BaseMoveForce), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_APlayerPawn_Statics::NewProp_BaseMoveForce_MetaData), Z_Construct_UClass_APlayerPawn_Statics::NewProp_BaseMoveForce_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APlayerPawn_Statics::NewProp_TargetMoveForce_MetaData[] = {
		{ "Category", "PlayerPawn" },
		{ "ModuleRelativePath", "Public/PlayerPawn.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_APlayerPawn_Statics::NewProp_TargetMoveForce = { "TargetMoveForce", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(APlayerPawn, TargetMoveForce), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_APlayerPawn_Statics::NewProp_TargetMoveForce_MetaData), Z_Construct_UClass_APlayerPawn_Statics::NewProp_TargetMoveForce_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APlayerPawn_Statics::NewProp_ShiftMultiplayer_MetaData[] = {
		{ "Category", "PlayerPawn" },
		{ "ModuleRelativePath", "Public/PlayerPawn.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_APlayerPawn_Statics::NewProp_ShiftMultiplayer = { "ShiftMultiplayer", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(APlayerPawn, ShiftMultiplayer), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_APlayerPawn_Statics::NewProp_ShiftMultiplayer_MetaData), Z_Construct_UClass_APlayerPawn_Statics::NewProp_ShiftMultiplayer_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_APlayerPawn_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APlayerPawn_Statics::NewProp_PlayerCollisionComponent,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APlayerPawn_Statics::NewProp_BaseMoveForce,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APlayerPawn_Statics::NewProp_TargetMoveForce,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APlayerPawn_Statics::NewProp_ShiftMultiplayer,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_APlayerPawn_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<APlayerPawn>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_APlayerPawn_Statics::ClassParams = {
		&APlayerPawn::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_APlayerPawn_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_APlayerPawn_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_APlayerPawn_Statics::Class_MetaDataParams), Z_Construct_UClass_APlayerPawn_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_APlayerPawn_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_APlayerPawn()
	{
		if (!Z_Registration_Info_UClass_APlayerPawn.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_APlayerPawn.OuterSingleton, Z_Construct_UClass_APlayerPawn_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_APlayerPawn.OuterSingleton;
	}
	template<> STEALANDRUN_API UClass* StaticClass<APlayerPawn>()
	{
		return APlayerPawn::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(APlayerPawn);
	APlayerPawn::~APlayerPawn() {}
	struct Z_CompiledInDeferFile_FID_StealAndRun_Source_StealAndRun_Public_PlayerPawn_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_StealAndRun_Source_StealAndRun_Public_PlayerPawn_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_APlayerPawn, APlayerPawn::StaticClass, TEXT("APlayerPawn"), &Z_Registration_Info_UClass_APlayerPawn, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(APlayerPawn), 2510706802U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_StealAndRun_Source_StealAndRun_Public_PlayerPawn_h_3896748140(TEXT("/Script/StealAndRun"),
		Z_CompiledInDeferFile_FID_StealAndRun_Source_StealAndRun_Public_PlayerPawn_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_StealAndRun_Source_StealAndRun_Public_PlayerPawn_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
