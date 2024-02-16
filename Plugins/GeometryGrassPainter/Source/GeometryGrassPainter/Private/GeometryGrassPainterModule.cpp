// Copyright Epic Games, Inc. All Rights Reserved.

#include "GeometryGrassPainterModule.h"
#include "GeometryGrassPainterEditorModeCommands.h"

#define LOCTEXT_NAMESPACE "GeometryGrassPainterModule"

void FGeometryGrassPainterModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module

	FGeometryGrassPainterEditorModeCommands::Register();
}

void FGeometryGrassPainterModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.

	FGeometryGrassPainterEditorModeCommands::Unregister();
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FGeometryGrassPainterModule, GeometryGrassPainterEditorMode)