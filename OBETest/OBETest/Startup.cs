using Microsoft.Owin;
using Owin;

[assembly: OwinStartupAttribute(typeof(OBETest.Startup))]
namespace OBETest
{
    public partial class Startup {
        public void Configuration(IAppBuilder app) {
            ConfigureAuth(app);
        }
    }
}
