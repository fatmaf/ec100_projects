<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="loadDataPage.aspx.cs" Inherits="OBETest._Default" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title>Load Data</title>
</head>
<body>
    <form id="loadData" runat="server">
    <div>
    
        <asp:Wizard ID="Wizard1" runat="server">
            <WizardSteps>
                <asp:WizardStep runat="server" title="Load Data">
                </asp:WizardStep>
                <asp:WizardStep runat="server" title="Import CMS File">
                </asp:WizardStep>
                <asp:WizardStep runat="server" Title="Details">
                </asp:WizardStep>
                <asp:WizardStep runat="server" Title="PLO/CLOs">
                </asp:WizardStep>
                <asp:WizardStep runat="server" Title="PLO/CLO Assesment Mapping">
                </asp:WizardStep>
            </WizardSteps>
        </asp:Wizard>
    
    </div>
    </form>
</body>
</html>
