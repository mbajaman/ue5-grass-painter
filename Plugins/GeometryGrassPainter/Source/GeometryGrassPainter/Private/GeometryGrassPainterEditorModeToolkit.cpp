// Copyright Epic Games, Inc. All Rights Reserved.

#include "GeometryGrassPainterEditorModeToolkit.h"
#include "GeometryGrassPainterEditorMode.h"
#include "Engine/Selection.h"

#include "Modules/ModuleManager.h"
#include "PropertyEditorModule.h"
#include "IDetailsView.h"
#include "EditorModeManager.h"

#define LOCTEXT_NAMESPACE "GeometryGrassPainterEditorModeToolkit"

FGeometryGrassPainterEditorModeToolkit::FGeometryGrassPainterEditorModeToolkit()
{
}

void FGeometryGrassPainterEditorModeToolkit::Init(const TSharedPtr<IToolkitHost>& InitToolkitHost, TWeakObjectPtr<UEdMode> InOwningMode)
{
	FModeToolkit::Init(InitToolkitHost, InOwningMode);
}

void FGeometryGrassPainterEditorModeToolkit::GetToolPaletteNames(TArray<FName>& PaletteNames) const
{
	PaletteNames.Add(NAME_Default);
}


FName FGeometryGrassPainterEditorModeToolkit::GetToolkitFName() const
{
	return FName("GeometryGrassPainterEditorMode");
}

FText FGeometryGrassPainterEditorModeToolkit::GetBaseToolkitName() const
{
	return LOCTEXT("DisplayName", "GeometryGrassPainterEditorMode Toolkit");
}

#undef LOCTEXT_NAMESPACE
