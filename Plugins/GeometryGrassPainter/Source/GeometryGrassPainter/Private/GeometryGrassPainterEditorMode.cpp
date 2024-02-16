// Copyright Epic Games, Inc. All Rights Reserved.

#include "GeometryGrassPainterEditorMode.h"
#include "GeometryGrassPainterEditorModeToolkit.h"
#include "EdModeInteractiveToolsContext.h"
#include "InteractiveToolManager.h"
#include "GeometryGrassPainterEditorModeCommands.h"


//////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////// 
// AddYourTool Step 1 - include the header file for your Tools here
//////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////// 
#include "Tools/GeometryGrassPainterSimpleTool.h"
#include "Tools/GeometryGrassPainterInteractiveTool.h"

// step 2: register a ToolBuilder in FGeometryGrassPainterEditorMode::Enter() below


#define LOCTEXT_NAMESPACE "GeometryGrassPainterEditorMode"

const FEditorModeID UGeometryGrassPainterEditorMode::EM_GeometryGrassPainterEditorModeId = TEXT("EM_GeometryGrassPainterEditorMode");

FString UGeometryGrassPainterEditorMode::SimpleToolName = TEXT("GeometryGrassPainter_ActorInfoTool");
FString UGeometryGrassPainterEditorMode::InteractiveToolName = TEXT("GeometryGrassPainter_MeasureDistanceTool");


UGeometryGrassPainterEditorMode::UGeometryGrassPainterEditorMode()
{
	FModuleManager::Get().LoadModule("EditorStyle");

	// appearance and icon in the editing mode ribbon can be customized here
	Info = FEditorModeInfo(UGeometryGrassPainterEditorMode::EM_GeometryGrassPainterEditorModeId,
		LOCTEXT("ModeName", "GeometryGrassPainter"),
		FSlateIcon(),
		true);
}


UGeometryGrassPainterEditorMode::~UGeometryGrassPainterEditorMode()
{
}


void UGeometryGrassPainterEditorMode::ActorSelectionChangeNotify()
{
}

void UGeometryGrassPainterEditorMode::Enter()
{
	UEdMode::Enter();

	//////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////
	// AddYourTool Step 2 - register the ToolBuilders for your Tools here.
	// The string name you pass to the ToolManager is used to select/activate your ToolBuilder later.
	//////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////// 
	const FGeometryGrassPainterEditorModeCommands& SampleToolCommands = FGeometryGrassPainterEditorModeCommands::Get();

	RegisterTool(SampleToolCommands.SimpleTool, SimpleToolName, NewObject<UGeometryGrassPainterSimpleToolBuilder>(this));
	RegisterTool(SampleToolCommands.InteractiveTool, InteractiveToolName, NewObject<UGeometryGrassPainterInteractiveToolBuilder>(this));

	// active tool type is not relevant here, we just set to default
	GetToolManager()->SelectActiveToolType(EToolSide::Left, SimpleToolName);
}

void UGeometryGrassPainterEditorMode::CreateToolkit()
{
	Toolkit = MakeShareable(new FGeometryGrassPainterEditorModeToolkit);
}

TMap<FName, TArray<TSharedPtr<FUICommandInfo>>> UGeometryGrassPainterEditorMode::GetModeCommands() const
{
	return FGeometryGrassPainterEditorModeCommands::Get().GetCommands();
}

#undef LOCTEXT_NAMESPACE
